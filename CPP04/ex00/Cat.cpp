#include <iostream>
#include "Cat.hpp"

Cat::Cat():
	Animal("Cat")
{
	std::cout << "Cat: [Default Constructor Called]" << std::endl;
}

Cat::Cat(const Cat &other):
	Animal(other._type)
{
	std::cout << "Cat: [Copy Constructor Called]" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: [Assignment Operator Called]" << std::endl;

	if (this != &other)
		_type = other._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat: [Meow Meow]" << std::endl;
}
