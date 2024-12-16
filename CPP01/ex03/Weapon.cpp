#include "Weapon.hpp"

Weapon::Weapon(const std::string &name): //| Construtor
		_type(name)
{
}

Weapon::~Weapon() //| Destrutor
{
}

void Weapon::setType(const std::string &type) //| Setter
{
	this->_type = type;
}

const std::string &Weapon::getType() const //| Getter
{
	return (this->_type);
}
