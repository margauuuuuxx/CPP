#include "../includes/Weapon.class.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon() {}

void    Weapon::setType(std::string type) { this->type = type; }
const std::string&  Weapon::getType() { return (type); }