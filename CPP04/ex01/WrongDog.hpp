#pragma once

# include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog &other);
        ~WrongDog();

        WrongDog &operator=(const WrongDog &other);

		void makeSound() const;

    private:
};
