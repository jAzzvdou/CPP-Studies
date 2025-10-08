#pragma once

# include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
		WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &other);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &other);

        std::string getType() const; //| Somente para printar o tipo do animal.
        void makeSound() const; //| NÃO TEM VIRTUAL NESSA CLASSE.
		
    protected:
    	std::string _type;
};
