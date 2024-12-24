#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat():
        WrongAnimal("WrongCat")
{
        std::cout << "*** WrongCat: [Default Constructor Called] ***" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other):
        WrongAnimal(other._type)
{
        std::cout << "*** WrongCat: [Copy Constructor Called] ***" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
        std::cout << "*** WrongCat: [Assignment Operator Called] ***" << std::endl;

        if (this != &other)
                _type = other._type;
        return (*this);
}

void WrongCat::makeSound() const
{
        std::cout << "*** WrongCat: [Meow Meow] ***" << std::endl;
}
