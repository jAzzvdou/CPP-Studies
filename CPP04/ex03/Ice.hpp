#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const AMateria &other);
		~Ice();

		Ice &operator=(const AMateria &other);

		AMateria *clone(const AMateria &other);
		void use(ICharacter &target);
	private:
};

#endif //| ICE_HPP
