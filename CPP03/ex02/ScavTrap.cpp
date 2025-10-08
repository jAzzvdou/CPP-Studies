#include <iostream>
#include "ScavTrap.hpp"

#define GREEN "\033[32m"
#define LIME "\033[92m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GRAY "\033[37m"
#define RESET "\033[0m"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: [ Default Constructor Called ]" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "* ScavTrap " << GREEN << this->_name << RESET << " is born! *" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap: [ Default Destructor Called ]" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap: [ Copy Constructor Called ]" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "[ Copy Assignment Operator Called ]" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other); //| Operador de atribuição herdado, faz o mesmo papel.
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
		std::cout << YELLOW << "Oh, no! ScavTrap " << this->_name << " has no enough hit points to attack!" << RESET << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << YELLOW << "Oh, no! ScavTrap " << this->_name << " has no enough energy points to attack!" << RESET << std::endl;
	else
	{
		std::cout << "Wow! ScavTrap " << this->_name << " attacks " << target << ", causing " << RED << this->_attackDamage << RESET << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ScavTrap::guardGate()
{
	if (this->_hitPoints < 1)
		std::cout << GRAY << "ScavTrap " << this->_name << " is already dead!" << RESET << std::endl;
	else
		std::cout << LIME << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << RESET << std::endl;
}
