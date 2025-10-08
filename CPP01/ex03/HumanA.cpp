#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name), _weapon(weapon) {} //| Construtor

HumanA::~HumanA() {} //| Destrutor

void HumanA::attack() const { std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl; } //| Método
