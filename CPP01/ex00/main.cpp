#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = new Zombie("Bob");
	zombie->announce();
	delete (zombie);

	randomChump("Steve");

	return (0);
}
