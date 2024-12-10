#include <iostream>
#include "Contact.hpp"

Contact::Contact() //| Construtor
{
}

Contact::Contact(const std::string &first_name,
		 const std::string &last_name,
		 const std::string &nickname,
		 const std::string &phone_number,
		 const std::string &darkest_secret):
		 _first_name(first_name),
		 _last_name(last_name),
		 _nickname(nickname),
		 _phone_number(phone_number),
		 _darkest_secret(darkest_secret)
{
}

void Contact::displayShort(void) const 
{
	std::cout << std::setw(10) << this->_first_name << "|";
	std::cout << std::setw(10) << this->_last_name << "|";
	std::cout << std::setw(10) << this->_nickname << "|" << std::endl;
}

void Contact::displayFull(void) const
{
	std::cout << "First Name: " << this->_first_name << std::endl;
	std::cout << "Last Name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
}

Contact::~Contact() //| Destrutor
{
}
