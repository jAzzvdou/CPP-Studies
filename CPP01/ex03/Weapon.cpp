#include "Weapon.hpp"

Weapon::Weapon(const std::string &name): //| Construtor
		_type(name)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const //| Getter
{
	return (this->_type);
}

void Weapon::setType(const std::string &type)
{
	this->_type = type;
}
