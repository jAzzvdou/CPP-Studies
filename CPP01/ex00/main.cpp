#include "Zombie.hpp"

int	main(void)
{
	//| Criado na stack, não precisa de delete porque será destruído automaticamente no final do escopo.
	Zombie zombie1 = Zombie();
	//| Utiliza '.' para acessar os método porque é uma instância direta, não um ponteiro.
	zombie1.announce();

	//| Criado na heap, precisa de delete, pois não será destruído automaticamente.
	Zombie *zombie2 = newZombie("John");
	//| Dentro de newZombie já foi feito o announce, mas não o delete.
	delete (zombie2);

	//| Criado na heap, precisa de delete.
	Zombie *zombie3 = new Zombie("Bob");
	//| Utiliza '->' pois é um ponteiro.
	zombie3->announce();
	delete (zombie3);

	//| Criado na heap, usa announce e já deleta.
	randomChump("Steve");

	return (0);
}
