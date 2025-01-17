#include "Character.hpp"

Character::Character():
	_name("Default")
{
	for (int i = 0; i < 4; i++)
		this->_spells[i] = NULL;
}

Character::Character(const std::string &name):
				_name(name)
{
	for (int i = 0; i < 4; i++)
		this->_spells[i] = NULL;
}

Character::Character(const Character &other):
			_name(other._name)
{
	for (int i = 0; i < 4; i++)
		this->_spells[i] = other._spells[i];
}

Character::~Character()
{
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_spells[i])
				delete this->_spells[i];
			this->_spells[i] = other._spells[i]->clone();
		}
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_spells[i] == NULL)
		{
			this->_spells[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_spells[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_spells[idx])
		this->_spells[idx]->use(target);
}
