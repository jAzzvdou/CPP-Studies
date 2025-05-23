#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
	public:
		ClapTrap();					//| Construtor padrão.
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);		//| Construtor de cópia.
		~ClapTrap();					//| Destrutor padrão.

		ClapTrap &operator=(const ClapTrap &other);	//| Operador de atribuição.

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

#endif //| CLAPTRAP_HPP
