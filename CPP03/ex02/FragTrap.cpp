#include <iostream>
#include "FragTrap.hpp"

#define GREEN "\033[32m"
#define LIME "\033[92m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GRAY "\033[37m"
#define RESET "\033[0m"

FragTrap::FragTrap(): ClapTrap()
{
        this->_hitPoints = 100;
        this->_energyPoints = 100;
        this->_attackDamage = 30;
        std::cout << "FragTrap: { Default Constructor Called }" << std::endl;
}

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
        this->_hitPoints = 100;
        this->_energyPoints = 100;
        this->_attackDamage = 30;
        std::cout << "# FragTrap " << GREEN << this->_name << RESET << " is born! #" << std::endl;
}

FragTrap::~FragTrap() { std::cout << "FragTrap: { Default Destructor Called }" << std::endl; }

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
        std::cout << "FragTrap: { Copy Constructor Called }" << std::endl;
        *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
        std::cout << "{ Copy Assignment Operator Called }" << std::endl;

        if (this != &other)
                ClapTrap::operator=(other); //| Operador de atribuição herdado, faz o mesmo papel.
        return (*this);
}

void FragTrap::highFivesGuys(void) { std::cout << this->_name << ", its high fives time! (^.^)" << std::endl; }
