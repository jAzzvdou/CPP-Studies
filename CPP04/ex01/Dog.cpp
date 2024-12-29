#include <iostream>
#include "Dog.hpp"

Dog::Dog():
        Animal("Dog"),
	_brain(new Brain())
{
        std::cout << "Dog: (Default Constructor Called)" << std::endl;
}

Dog::Dog(const Dog &other):
        Animal(other._type),
	_brain(new Brain(*other._brain))
{
        std::cout << "Dog: (Copy Constructor Called)" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog: (Default Destructor Called)" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
        std::cout << "Dog: (Assignment Operator Called)" << std::endl;

        if (this != &other)
                _type = other._type;

	delete this->_brain;
	this->_brain = new Brain(*other._brain);

        return (*this);
}

void Dog::makeSound() const
{
        std::cout << "Dog: (Bark Bark)" << std::endl;
}
