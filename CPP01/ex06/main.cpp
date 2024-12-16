#include <iostream>
#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Error! Usage: ./halfFilter <complain>" << std::endl, 1);

	Harl harl;

	harl.complain(av[1]);

	return (0);
}
