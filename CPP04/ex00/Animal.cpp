#include <iostream>
#include "Animal.hpp"

Animal::Animal():
	_type("Animal")
{
	std::cout << "| Animal Default Constructor Called |" << std::endl;
}

Animal::Animal(const std::string &type):
				_type(type)
{
	std::cout << "| Animal Constructor Called |" << std::endl;
}

Animal::Animal(const Animal &other):
		_type(other._type)
{
	std::cout << "| Animal Copy Constructor Called |" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "| Animal Assignment Operator Called |" << std::endl;

	if (this != &other)
		_type = other._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "| Animal Destructor Called |" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "| Animal Sound |" << std::endl;
}
