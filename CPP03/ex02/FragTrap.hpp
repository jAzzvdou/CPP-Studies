#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();                                     //| Construtor padrão.
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);                //| Construtor de cópia.
		~FragTrap();                                    //| Destrutor padrão.

		FragTrap &operator=(const FragTrap &other);     //| Operador de atribuição.

		void highFivesGuys(void);

	private:
};

#endif //| FRAGTRAP_HPP
