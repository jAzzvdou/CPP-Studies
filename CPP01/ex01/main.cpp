#include "Zombie.hpp"

int	main(void)
{
	//| Quantidade de zombies a serem criados.
	int i = 10;

	//| Aqui eu cria a horda de zombies e retorna o ponteiro do primeiro zombie.
	Zombie *zombies = zombieHorde(i, "Zombies");
	//| Fazendo cada um deles falar.
	for (int j = 0; j < i; j++)
		zombies[j].announce();
	//| Usando delete em todos os zombies para não dar vazamento.
	delete [] zombies;

	return (0);
}
