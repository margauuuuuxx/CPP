#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

#include "AMateria.class.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &other);
        Ice& operator=(const Ice &other);
        ~Ice();

        Ice* clone() const;
        virtual void use(ICharacter& target);
};

#endif