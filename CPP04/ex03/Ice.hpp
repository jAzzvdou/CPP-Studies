#pragma once

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const AMateria &other);
		~Ice();

		Ice &operator=(const AMateria &other);

		AMateria *clone() const;
		void use(ICharacter &target);
};
