#include "Zombie.hpp"

int	main(void)
{
	int i = 10;

	Zombie *zombies = zombieHorde(i, "Zombies");
	for (int j = 0; j < i; j++)
		zombies[j].announce();
	delete [] zombies;

	return (0);
}
