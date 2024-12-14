#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &type); //| Construtor
		~Weapon(); //| Destrutor

		//|----------| Métodos |----------|//
		const std::string &getType const;
		void setType(const std::string &type);
	private:
		std::string _type;
}

#endif //| WEAPON_HPP
