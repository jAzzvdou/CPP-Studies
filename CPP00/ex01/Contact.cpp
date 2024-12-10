#include "Contact.hpp"

Contact::Contact() //| Construtor
{
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret) //| Construtor
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_dark_secret = dark_secret;
}

Contact::~Contact() //| Destrutor
{
}
