#pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
    public:
        Dog();
        Dog(const Dog &other);
        ~Dog();

        Dog &operator=(const Dog &other);

        void makeSound() const;
        
    private:
		Brain *_brain;
};
