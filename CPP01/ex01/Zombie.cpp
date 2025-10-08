#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(): _name("NoNamedZombie") {} //| Construtor

Zombie::Zombie(const std::string &name): _name(name) {}

Zombie::~Zombie() { std::cout << this->_name << " is dead" << std::endl; } //| Destrutor

void Zombie::announce() { std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::setName(const std::string &name) { this->_name = name; } //| Setter
