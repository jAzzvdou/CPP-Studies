#include <iostream>
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "! Tests !" << std::endl;
	std::cout << "\n...___---°°°| Testing FragTrap |°°°---___..." << std::endl;

	FragTrap frag("Fraggy");
	frag.attack("T01");
	frag.takeDamage(30);
	frag.beRepaired(20);

	std::cout << "\n...___---°°°| Testing 'FivesGuys' Function |°°°---___..." << std::endl;

	frag.highFivesGuys();

	std::cout << "\n...___---°°°| Testing Copy |°°°---___..." << std::endl;

	FragTrap fragCopy(frag);
	fragCopy.attack("Dummy01");

	std::cout << "\n...___---°°°| Testing Assignment |°°°---___..." << std::endl;

	FragTrap fragAssignment = frag;
	fragAssignment.attack("Dummy02");

	std::cout << "\n...___---°°°| Testing Destructors |°°°---___..." << std::endl;

	return (0);
}
