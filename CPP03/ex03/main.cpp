#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "! Tests !" << std::endl;
	std::cout << "\n...___---°°°| Testing DiamondTrap |°°°---___..." << std::endl;

	DiamondTrap Diamond("Diammy");
	Diamond.attack("T01");
	Diamond.takeDamage(10);
	Diamond.beRepaired(5);

	std::cout << "\n...___---°°°| Testing 'whoAmI' |°°°---___..." << std::endl;

	Diamond.whoAmI();

	std::cout << "\n...___---°°°| Testing Destructors |°°°---___..." << std::endl;

	return (0);
}
