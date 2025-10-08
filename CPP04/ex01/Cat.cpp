#include <iostream>
#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain()) { std::cout << "Cat: [Default Constructor Called]" << std::endl; }

Cat::Cat(const Cat &other): Animal(other._type), _brain(new Brain(*other._brain)) { std::cout << "Cat: [Copy Constructor Called]" << std::endl; }

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

void Cat::makeSound() const { std::cout << "Cat: [Meow Meow]" << std::endl; }
