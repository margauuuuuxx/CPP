#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Dog : public Animal
{
    private:
        Brain* dogBrain;
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        ~Dog();

        virtual void makeSound() const;
};

#endif