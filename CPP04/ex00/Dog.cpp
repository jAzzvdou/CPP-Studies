#include <iostream>
#include "Dog.hpp"

Dog::Dog(): Animal("Dog") { std::cout << "Dog: (Default Constructor Called)" << std::endl; }

Dog::Dog(const Dog &other): Animal(other._type) { std::cout << "Dog: (Copy Constructor Called)" << std::endl; }

Dog::~Dog() { std::cout << "Dog: (Default Destructor Called)" << std::endl; }

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: (Assignment Operator Called)" << std::endl;

    if (this != &other)
            _type = other._type;
    return (*this);
}

void Dog::makeSound() const { std::cout << "Dog: (Bark Bark)" << std::endl; }
