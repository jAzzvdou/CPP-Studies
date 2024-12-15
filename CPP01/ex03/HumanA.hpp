#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon); //| Construtor
		~HumanA(); //| Destrutor

		//|----------| Método |----------|//
		void attack();
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif //| HUMANA_HPP
