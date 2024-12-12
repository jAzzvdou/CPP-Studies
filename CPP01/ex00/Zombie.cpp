#include "Zombie.hpp"

Zombie::Zombie(): //| Construtor
	_name("NoNamedZombie")
{
}

Zombie::Zombie(std::string name):
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
