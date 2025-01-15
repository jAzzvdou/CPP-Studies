#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const AMateria &other);
		~Cure();

		Cure &operator=(const Cure &other);

		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif //| CURE_HPP
