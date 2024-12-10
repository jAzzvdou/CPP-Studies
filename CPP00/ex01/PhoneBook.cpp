#include "PhoneBook.hpp"

PhoneBook::PhoneBook() //| Constutor
{
}

void	PhoneBook::addContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First Name: " << std::endl;
	while (std::getline(std::cin, first_name) && first_name.empty())
		std::cout << "First Name: " << std::endl;

	std::cout << "Last Name: " << std::endl;
	while (std::getline(std::cin, last_name) && last_name.empty())
		std::cout << "Last Name: " << std::endl;

	std::cout << "Nickname: " << std::endl;
	while (std::getline(std::cin, nickname) && nickname.empty())
		std::cout << "Nickname: " << std::endl;

	std::cout << "Phone Number: " << std::endl;
	while (std::getline(std::cin, phone_number) && phone_number.empty())
		std::cout << "Phone Number: " << std::endl;

	std::cout << "Darkest Secret: " << std::endl;
	while (std::getline(std::cin, darkest_secret) && darkest_secret.empty())
		std::cout << "Darkest Secret: " << std::endl;
	
	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);

	static int i = 0;
	this->contacts[i] = contact;
	i++;
	if (i == 8)
		i = 0;
}

void	PhoneBook::searchContact(void) const
{
	this->displayContacts();

}

PhoneBook::~PhoneBook() //| Destrutor
{
}
