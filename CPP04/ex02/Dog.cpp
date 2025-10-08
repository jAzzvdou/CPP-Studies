#include <iostream>
#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
    std::cout << "Dog: (Default Constructor Called)" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other): AAnimal(other._type)
{
    std::cout << "Dog: (Copy Constructor Called)" << std::endl;
	this->_brain = new Brain(*other._brain);
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

void Dog::makeSound() const { std::cout << "Dog: (Bark Bark)" << std::endl; }
