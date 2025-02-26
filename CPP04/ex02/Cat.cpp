#include <iostream>
#include "Cat.hpp"

Cat::Cat():
	AAnimal("Cat")
{
	std::cout << "Cat: [Default Constructor Called]" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other):
	AAnimal(other._type)
{
	std::cout << "Cat: [Copy Constructor Called]" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat: [Default Destructor Called]" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: [Assignment Operator Called]" << std::endl;

	if (this != &other)
		_type = other._type;

	delete this->_brain;
	this->_brain = new Brain(*other._brain);

	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat: [Meow Meow]" << std::endl;
}
