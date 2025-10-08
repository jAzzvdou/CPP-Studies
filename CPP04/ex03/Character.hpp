#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character();
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		Character &operator=(const Character &other);

		const std::string &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

	private:
		std::string _name;
		AMateria *_spells[4];
};
