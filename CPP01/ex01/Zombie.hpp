#pragma once

# include <string>

class Zombie
{
	public:
		Zombie();								//| Construtor
		Zombie(const std::string &name);
		~Zombie();								//| Destrutor
		
		void announce( void );					//| Método para anunciar o nome do zombie.
		void setName(const std::string &name);	//| Setter

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
