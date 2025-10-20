#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return (std::cerr << "Usage: " << av[0] << " <numbers>" << std::endl, 1);
	
	try
	{
		PmergeMe sorter(ac, av);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}

//| Use o comando ./PmergeMe `shuf -i N1-N2 -n N2 | tr "\n" " "` para gerar números aleatórios e testar o programa