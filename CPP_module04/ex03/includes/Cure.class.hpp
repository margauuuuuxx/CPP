#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

#include "AMateria.class.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &other);
        Cure& operator=(const Cure &other);
        ~Cure();

        Cure* clone() const;
        virtual void use(ICharacter& target);
};

#endif 