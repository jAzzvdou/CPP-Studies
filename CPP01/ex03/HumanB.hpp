#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name); //| Construtor
		~HumanB(); //| Destrutor

		void setWeapon(const Weapon &weapon); //| Setter
		//|----------| Método |----------|//
		void attack() const;
	private:
		std::string _name;
		const Weapon *_weapon;
};

#endif //| HUMANB_HPP
