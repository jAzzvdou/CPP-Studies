#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const int value)
{
        this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
        this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
        *this = fixed;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
        this->_value = fixed.getRawBits();
        return (*this);
}

int Fixed::toInt( void ) const
{
        //| FLOAT -> INT.
        return (this->_value >> this->_fractionalBits);
}

float Fixed::toFloat( void ) const
{
        //| INT -> FLOAT.
        return ((float)this->_value / (1 << this->_fractionalBits));
}

int Fixed::getRawBits( void ) const
{
        return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
        this->_value = raw;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->_value > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->_value < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_value >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_value <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->_value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_value != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
        out << fixed.toFloat();
        return (out);
}
