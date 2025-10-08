#pragma once

# include <string>

class Animal
{
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		virtual ~Animal();

		Animal &operator=(const Animal &other);

		std::string getType() const;	//| Somente para printar o tipo do animal.
		virtual void makeSound() const;	//| Virtual pois eu posso mudar a implementação na classe derivada.

	protected:
		std::string _type;
};