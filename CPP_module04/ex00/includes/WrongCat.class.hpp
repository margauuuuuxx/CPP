#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &other);
        WrongCat& operator=(WrongCat const &other);
        ~WrongCat();

        void makeSound() const;
};

#endif 