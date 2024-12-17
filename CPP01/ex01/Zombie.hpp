#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie(); //| Construtor
		Zombie(const std::string &name);
		~Zombie(); //| Destrutor
		
		void announce( void );
		void setName(const std::string &name); //| Setter
	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif //| ZOMBIE_HPP
