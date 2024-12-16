#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(): //| Construtor
        _name("NoNamedZombie")
{
}

Zombie::Zombie(const std::string &name):
                _name(name)
{
}

Zombie::~Zombie() //| Destrutor
{
        std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce()
{
        std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) //| Setter
{
	this->_name = name;
}
