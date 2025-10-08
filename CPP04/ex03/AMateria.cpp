#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(): _type("Default") {}

AMateria::AMateria(const std::string &type): _type(type) {}

AMateria::AMateria(const AMateria &other): _type(other._type) {}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

const std::string &AMateria::getType() const { return (this->_type); }

void AMateria::use(ICharacter &target) { std::cout << "* use on " << target.getName() << " *" << std::endl; }
