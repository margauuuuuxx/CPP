#include "../includes/HumanB.class.hpp"

HumanB::HumanB(std::string name) : name(name), weaponB(NULL) {};
HumanB::~HumanB() {}


void    HumanB::attack()
{
    if (weaponB)
        std::cout << this->name << " attacks with their " << weaponB->getType() << std::endl;
    else 
        std::cout << this->name << " has no weapon " << std::endl;
}

void    HumanB::setWeapon(Weapon& weaponB)
{
    this->weaponB = &weaponB;
}