#pragma once

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon);	//| Construtor
		~HumanA();											//| Destrutor

		//|----------| Método |----------|//
		void attack() const;

	private:
		std::string _name;
		Weapon &_weapon;
};
