#ifndef IMATERIASOURCE_INTERFACE_HPP
# define IMATERIASOURCE_INTERFACE_HPP

#include "AMateria.class.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif 