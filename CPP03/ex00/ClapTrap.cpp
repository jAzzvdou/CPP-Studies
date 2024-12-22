#include <iostream>
#include "ClapTrap.hpp"

#define GREEN "\033[32m"
#define LIME "\033[92m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GRAY "\033[37m"
#define RESET "\033[0m"

ClapTrap::ClapTrap():
	_name("NoNamed"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "| Default Constructor Called |" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):
			_name(name),
			_hitPoints(10),
			_energyPoints(10),
			_attackDamage(0)
{
	std::cout << "ClapTrap " << GREEN << this->_name << RESET << " is born!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "| Default Destructor Called |" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "| Copy Constructor Called |" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "| Copy Assignment Operator Called |" << std::endl;

	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints < 1)
		std::cout << YELLOW << "ClapTrap " << this->_name << " has no enough hit points to attack!" << RESET << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << YELLOW << "ClapTrap " << this->_name << " has no enough energy points to attack!" << RESET << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << RED << this->_attackDamage << RESET << " points of damage!" << std::endl;
		this->_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << GRAY << "ClapTrap " << this->_name << " is already dead!" << RESET << std::endl;
	else
	{
	std::cout << "ClapTrap " << this->_name << " takes " << RED << amount << RESET << " points of damage!" << std::endl;
		if (this->_hitPoints < amount)
			this->_hitPoints = 0;
		else
			this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints < 1)
		std::cout << GRAY << "ClapTrap " << this->_name << " is already dead!" << RESET << std::endl;
	else if (this->_energyPoints < 1)
		std::cout << YELLOW << "ClapTrap " << this->_name << " has no enough energy points to be repaired!" << YELLOW << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->_name << " is being repaired for " << LIME << amount << RESET << " points!" << std::endl;
		if (this->_hitPoints + amount > 10)
			this->_hitPoints = 10;
		else
			this->_hitPoints += amount;
	}
}
