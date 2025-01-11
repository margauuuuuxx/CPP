#include "../includes/DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor has been called" << std::endl;
    this->hitPts = FragTrap::getHitsPts();
    this->energyPts = ScavTrap::getEnergyPts();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap string constructir has been called" << std::endl;
    this->hitPts = FragTrap::getHitsPts();
    this->energyPts = ScavTrap::getEnergyPts();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy constructor has been called" << std::endl;
    *this = other;
}

DiamondTrap&    DiamondTrap::operator = (const DiamondTrap &other)
{
    if (this != &other)
    {
        setName(other.name);
    }
}