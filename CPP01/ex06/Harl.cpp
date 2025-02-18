#include <iostream>
#include "Harl.hpp"

Harl::Harl() //| Construtor
{
}

Harl::~Harl() //| Destrutor
{
}

void Harl::debug( void ) const
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	//| Transformar a string toda para maiúscula.
	int len = level.length();
	for (int i = 0; i < len; i++)
		level[i] = toupper(level[i]);

        //| Array de ponteiros para funções.
        void (Harl::*ptrF[4])( void ) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	switch (level[0])
	{
		case 'D':
			(this->*ptrF[0])();
			break;
		case 'I':
			(this->*ptrF[1])();
			break;
		case 'W':
			(this->*ptrF[2])();
			break;
		case 'E':
			(this->*ptrF[3])();
			break;
		default:
			break;
	}
}
