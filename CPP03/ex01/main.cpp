#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "! Tests !" << std::endl;
	std::cout << "\n...___---°°°| Testing ClapTrap |°°°---___..." << std::endl;

	ClapTrap clap("Clappy");
	clap.attack("T01");
	clap.takeDamage(5);
	clap.beRepaired(4);
	clap.takeDamage(3);
	clap.beRepaired(2);

	std::cout << "\n...___---°°°| Testing ScavTrap |°°°---___..." << std::endl;
	
	ScavTrap scav("Scavy");
	scav.attack("T02");
	scav.takeDamage(50);
	scav.beRepaired(40);
	scav.takeDamage(30);
	scav.beRepaired(20);

	std::cout << "\n...___---°°°| Testing Copy |°°°---___..." << std::endl;

	ScavTrap copy(scav);
	copy.attack("*Dummy01*");

	std::cout << "\n...___---°°°| Testing Assignment |°°°---___..." << std::endl;

	ScavTrap assignment = scav;
	assignment.attack("*Dummy02*");


	std::cout << "\n...___---°°°| Testing Destructors |°°°---___..." << std::endl;

	return (0);
}
