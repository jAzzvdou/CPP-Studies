#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() //| Constutor
{
}

PhoneBook::~PhoneBook() //| Destrutor
{
}

std::string	getField(const std::string &message)
{
	std::string field;
	do
	{
		std::cout << message << std::endl;
		std::getline(std::cin, field);
	}	while (!std::cin.eof() && field.empty());
	return (field);
}

void	PhoneBook::addContact(void)
{
	Contact contact(getField("Enter the first name: "),
			getField("Enter the last name: "),
			getField("Enter the nickname: "),
			getField("Enter the phone number: "),
			getField("Enter the darkest secret: "));

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
