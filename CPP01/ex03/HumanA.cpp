#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): //| Construtor
		_name(name),
		_weapon(weapon)
{
}

HumanA::~HumanA() //| Destrutor
{
}

void HumanA::attack() const //| Método
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
