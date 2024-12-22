#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap();

		DiamondTrap &operator=(const DiamondTrap &other);

		using ScavTrap::attack; //| Usar 'attack()' de ScavTrap.
		void whoAmI();
	private:
		std::string _name;
}

#endif //| DIAMONDTRAP_HPP
