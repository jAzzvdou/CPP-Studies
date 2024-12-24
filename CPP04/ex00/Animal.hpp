#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		~Animal();

		Animal &operator=(const Animal &other);

		std::string getType() const; //| Somente para printar o tipo do animal.
		virtual void makeSound() const; //| Virtual pois eu posso mudar a implementação na classe derivada.
	protected:
		std::string _type;
};

#endif //| ANIMAL_HPP
