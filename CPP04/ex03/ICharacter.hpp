#pragma once

# include <string>

class AMateria; //| Declarei AMateria para evitar dependencia circular, pois em AMateria.hpp temos '#include ICharacter.hpp'.

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual const std::string &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};
