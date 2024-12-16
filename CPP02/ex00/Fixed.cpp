#include <iostream>
#include "Fixed.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

Fixed::Fixed(): _value(0) //| Construtor padrão.
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &fixed) //| Construtor de cópia.
{
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
	*this = fixed;
}

Fixed::~Fixed() //| Destrutor.
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) //| Operador de atribuição.
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	this->_value = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const //| Getter.
{
	std::cout << MAGENTA << "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) //| Setter.
{
	std::cout << CYAN << "setRawBits member function called" << RESET << std::endl;
	this->_value = raw;
}
