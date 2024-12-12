#include "PhoneBook.hpp"

PhoneBook::PhoneBook() //| Constutor
{
}

void	getField(std::string &field, const std::string &message)
{
	do
	{
		std::cout << message << std::endl;
		std::getline(std::cin, field);
	}	while (!std::cin.eof() && field.empty());
}

void	PhoneBook::addContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	getField(first_name, "Enter the first name: ");
	getField(last_name, "Enter the last name: ");
	getField(nickname, "Enter the nickname: ");
	getField(phone_number, "Enter the phone number: ");
	getField(darkest_secret, "Enter the darkest secret: ");

	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);

	static int i = 0;
	this->_contacts[i] = contact;
	i++;
	if (i == 8)
		i = 0;
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|";
		this->_contacts[i].displayShort();
	}
}

void	PhoneBook::searchContact(void) const
{
	this->displayContacts();

	std::string index;
	do
	{
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, index);
	}	while (!std::cin.eof() && (index.empty() || index.size() != 1 || index[0] < '0' || index[0] > '7'));

	int i = index[0] - '0';
	this->_contacts[i].displayFull();
}

PhoneBook::~PhoneBook() //| Destrutor
{
}
