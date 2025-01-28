#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

#include "IMateriaSource.interface.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource& operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *ref);
        AMateria* createMateria(std::string const & type);
};

#endif 