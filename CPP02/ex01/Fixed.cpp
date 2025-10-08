#include <iostream>
#include <cmath>
#include "Fixed.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define ORANGE "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Fixed::Fixed(): _value(0) { std::cout << GREEN << "Default constructor called" << RESET << std::endl; } //| Construtor padrão

Fixed::Fixed(const int value) //| Construtor de cópia INT
{
	std::cout << ORANGE << "Int constructor called" << RESET << std::endl;
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) //| Construtor de cópia FLOAT
{
	std::cout << ORANGE << "Float constructor called" << RESET << std::endl;
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) //| Construtor de cópia
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = fixed;
}

Fixed::~Fixed() { std::cout << RED << "Destructor called" << RESET << std::endl; } //| Destrutor

Fixed &Fixed::operator=(const Fixed &fixed) //| Operator de atribuição
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

int Fixed::toInt( void ) const { return (this->_value >> this->_fractionalBits); } //| FLOAT -> INT

float Fixed::toFloat( void ) const { return ((float)this->_value / (1 << this->_fractionalBits)); } //| INT -> FLOAT

int Fixed::getRawBits( void ) const { return (this->_value); } //| Getter _value

void Fixed::setRawBits( int const raw ) { this->_value = raw; } //| Setter _value

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) //| Operator de inserção
{
	//| Com o operador de inserção podemos usar o 'std::cout' diretamente com um objeto da classe 'Fixed'
	out << fixed.toFloat();
	return (out);
}
