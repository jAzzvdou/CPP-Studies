#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie(); //| Construtor
		Zombie(std::string name);
		~Zombie(); //| Destrutor
		
		void announce();
		void setName(std::string name);
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif //| ZOMBIE_HPP
