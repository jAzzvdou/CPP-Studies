#pragma once

# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(const std::string &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();

		AMateria &operator=(const AMateria &other);

		const std::string &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string _type;
};

//| AMateria é uma classe abstrada e só conseguiremos instanciá-la na classe ICE e CURE.
