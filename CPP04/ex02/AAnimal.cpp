#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal():
	_type("AAnimal")
{
	std::cout << "| AAnimal Default Constructor Called |" << std::endl;
}

AAnimal::AAnimal(const std::string &type):
				_type(type)
{
	std::cout << "| AAnimal Constructor Called |" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other):
		_type(other._type)
{
	std::cout << "| AAnimal Copy Constructor Called |" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "| AAnimal Destructor Called |" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "| AAnimal Assignment Operator Called |" << std::endl;

	if (this != &other)
		_type = other._type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (_type);
}
