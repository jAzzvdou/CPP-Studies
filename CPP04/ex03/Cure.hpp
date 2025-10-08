#pragma once

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const AMateria &other);
		~Cure();

		Cure &operator=(const AMateria &other);

		AMateria *clone() const;
		void use(ICharacter &target);
};
