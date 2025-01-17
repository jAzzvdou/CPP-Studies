#include <iostream>
#include "Cure.hpp"

Cure::Cure():
	AMateria("cure")
{
}

Cure::Cure(const AMateria &other):
	AMateria(other)
{
}

Cure::~Cure()
{
}

Cure &Cure::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
