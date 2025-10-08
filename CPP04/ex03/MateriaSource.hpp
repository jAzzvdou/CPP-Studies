#pragma once

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &other);

		void learnMateria(AMateria *m);
		AMateria *createMateria(const std::string &type);

	private:
		AMateria *_spells[4];
};

