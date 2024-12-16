#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	public:
		Weapon(const std::string &type); //| Construtor
		~Weapon(); //| Destrutor

		void setType(const std::string &type); //| Setter
		const std::string &getType() const; //| Getter
	private:
		std::string _type;
};

#endif //| WEAPON_HPP
