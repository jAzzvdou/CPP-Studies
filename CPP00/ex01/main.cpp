#include <iostream>
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to the phone book!" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT." << std::endl;
		std::getline(std::cin, command);

		while (command != "ADD" || command != "SEARCH" || command != "EXIT")
			std::cout << "Invalid command, try again: " << std::endl;
			std::getline(std::cin, command);

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
```
