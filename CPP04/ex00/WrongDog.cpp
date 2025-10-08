#include <iostream>
#include "WrongDog.hpp"

WrongDog::WrongDog(): WrongAnimal("WrongDog") { std::cout << "*** WrongDog: (Default Constructor Called) ***" << std::endl; }

WrongDog::WrongDog(const WrongDog &other): WrongAnimal(other._type) { std::cout << "*** WrongDog: (Copy Constructor Called) ***" << std::endl; }

WrongDog::~WrongDog() { std::cout << "*** WrongDog: (Default Destructor Called) ***" << std::endl; }

WrongDog &WrongDog::operator=(const WrongDog &other)
{
    std::cout << "*** WrongDog: (Assignment Operator Called) ***" << std::endl;

    if (this != &other)
            _type = other._type;
    return (*this);
}

void WrongDog::makeSound() const { std::cout << "*** WrongDog: (Bark Bark) ***" << std::endl; }
