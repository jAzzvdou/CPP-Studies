#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():
        _type("WrongAnimal")
{
        std::cout << "{ WrongAnimal Default Constructor Called }" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type):
					_type(type)
{
	std::cout << "{ WrongAnimal Constructor Called }" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other):
                		_type(other._type)
{
        std::cout << "{ WrongAnimal Copy Constructor Called }" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
        std::cout << "{ WrongAnimal Assignment Operator Called }" << std::endl;

        if (this != &other)
                _type = other._type;
        return (*this);
}

WrongAnimal::~WrongAnimal()
{
        std::cout << "{ WrongAnimal Destructor Called }" << std::endl;
}

std::string WrongAnimal::getType() const
{
        return (_type);
}

void WrongAnimal::makeSound() const
{
        std::cout << "{ WrongAnimal Sound }" << std::endl;
}
