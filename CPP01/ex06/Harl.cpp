#include <iostream>
#include <map>
#include "Harl.hpp"

Harl::Harl() //| Construtor
{
}

Harl::~Harl() //| Destrutor
{
}

void Harl::debug( void ) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	//| Transformar a string toda para maiúscula.
	int len = level.length();
	for (int i = 0; i < len; i++)
		level[i] = toupper(level[i]);

	//| Array de ponteiros para funções.
	void (Harl::*ptrF[4])( void ) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	//| Map é uma estrutura de dados que armazena pares chave-valor, como um dicionário.
	std::map<std::string, int> map;
	map["DEFAULT"] = 0;
	map["DEBUG"] = 1;
	map["INFO"] = 2;
	map["WARNING"] = 3;
	map["ERROR"] = 4;

	switch (map[level])
	{
		case 1:	std::cout << "[ DEBUG ]" << std::endl;
			(this->*ptrF[0])();
			std::cout << std::endl;
			break;
		case 2:	std::cout << "[ INFO ]" << std::endl;
			(this->*ptrF[1])();
			std::cout << std::endl;
			break;
		case 3:	std::cout << "[ WARNING ]" << std::endl;
			(this->*ptrF[2])();
			std::cout << std::endl;
			break;
		case 4:	std::cout << "[ ERROR ]" << std::endl;
			(this->*ptrF[3])();
			std::cout << std::endl;
			break;
		default:	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
