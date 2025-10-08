#pragma once

# include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &other);

		std::string getType() const;		//| Somente para printar o tipo do animal.
		virtual void makeSound() const = 0; //| Transforma a classe em abstrada, ou seja, não pode ser instanciada diretamente.

	protected:
		std::string _type;
};
