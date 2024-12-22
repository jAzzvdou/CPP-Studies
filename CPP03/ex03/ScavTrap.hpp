#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();					//| Construtor padrão.
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);		//| Construtor de cópia.
		~ScavTrap();					//| Destrutor padrão.

		ScavTrap &operator=(const ScavTrap &other);	//| Operador de atribuição.

		void attack(const std::string &target);
		void guardGate();
	private:
};

#endif //| SCAVTRAP_HPP
