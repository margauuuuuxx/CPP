#include "../includes/Ice.class.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria("ice") { *this = other; }

Ice&    Ice::operator = (const Ice &other)
{
    if (this != &other)
        this->type = other.getType();
    return (*this);
}

Ice::~Ice() {}

Ice*    Ice::clone() const { return (new Ice(*this)); }

void    Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; }