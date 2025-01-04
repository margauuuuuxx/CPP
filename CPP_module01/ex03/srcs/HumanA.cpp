#include "../includes/HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon& weaponA) : name(name), weaponA(weaponA) { }

HumanA::~HumanA() {}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << weaponA.getType() << std::endl;
}