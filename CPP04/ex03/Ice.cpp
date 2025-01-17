#include <iostream>
#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
}

Ice::Ice(const AMateria &other):
	AMateria(other)
{
}

Ice::~Ice()
{
}

Ice &Ice::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
