#include "../includes/DiamondTrap.class.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor has been called" << std::endl;
    setName("Default");
    ClapTrap::setName("Default_clap_name");
    this->hitPts = FragTrap::getHitsPts();
    this->energyPts = ScavTrap::getEnergyPts();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap()
{
    std::cout << "DiamondTrap string constructor has been called" << std::endl;
    ClapTrap::setName(name + "_clap_name");
    this->name = name;
    this->hitPts = FragTrap::getHitsPts();
    this->energyPts = ScavTrap::getEnergyPts();
    this->attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap copy constructor has been called" << std::endl;
    *this = other;
}

DiamondTrap&    DiamondTrap::operator = (const DiamondTrap &other)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        setName(other.name);
        setHitPts(other.hitPts);
        setEnergyPts(other.energyPts);
        setAttackDamage(other.attackDamage);
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond trap name is : " << this->name << std::endl;
    std::cout << "ClapTrap name is : " << ClapTrap::name << std::endl;
}