#include <iostream>
#include "DiamondTrap.hpp"

#define GREEN "\033[32m"
#define LIME "\033[92m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GRAY "\033[37m"
#define RESET "\033[0m"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap: ( Default Constructor Called )" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "° DiamondTrap " << GREEN << this->_name << RESET << " is born! °" << std::endl;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap: ( Default Destructor Called )" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "( Copy Constructor Called )" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "( Copy Assignment Operator Called )" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

void DiamondTrap::whoAmI() { std::cout << "Hi! I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << "!" << std::endl; }
