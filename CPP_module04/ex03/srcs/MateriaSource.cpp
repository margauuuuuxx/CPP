#include "../includes/MateriaSource.class.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource&  MateriaSource::operator = (const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            this->source[i] = other.source[i];
    }
    return (*this);
}

MateriaSource::~MateriaSource() {}

void    MateriaSource::learnMateria(AMateria *ref)
{
    if (ref)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->source[i] == NULL)
            {
                this->source[i] = ref;
                return;
            }
        }
        std::cout << "MateriaSource is full" << std::endl;
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (type == this->source[i]->getType())
            return (this->source[i]->clone());
    }
    std::cout << "Cannot create MateriaSource: unknown type" << std::endl;
}