#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
        Animal();

    public:
        Animal(const Animal &other);
        Animal& operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0; // this is pure virtual allowing for abstract classes
        std::string getType() const;
};

#endif