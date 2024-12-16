#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name): //| Construtor
		_name(name)
{
}

HumanB::~HumanB() //| Destrutor
{
}

void HumanB::setWeapon(const Weapon &weapon) //| Setter
{
	this->_weapon = &weapon;
}

void HumanB::attack() const //| Método
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with!" << std::endl;
}
