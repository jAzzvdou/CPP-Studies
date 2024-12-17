#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Steve");

	claptrap.attack("EnderDragon");
	claptrap.takeDamage(100);
	claptrap.attack("EnderDragon");
	claptrap.beRepaired(5);

	return (0);
}
