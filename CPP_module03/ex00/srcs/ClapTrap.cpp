#include "../includes/ClapTrap.class.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPts(10), energyPts(10), attackDamage(0) { std::cout << "Default constructor has been called" << std::endl; }
ClapTrap::ClapTrap(std::string name) : name(name), hitPts(10), energyPts(10), attackDamage(0) { std::cout << "String constructor has been called" << std::endl; }
ClapTrap::~ClapTrap() { std::cout<< "Destructor has been called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor has been called" << std::endl;
    this->name = other.getName();
    this->hitPts = other.hitPts;
    this->energyPts = other.energyPts;
    this->attackDamage = other.attackDamage;
}

ClapTrap&   ClapTrap::operator = (const ClapTrap& other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->name = other.getName();
        this->hitPts = other.hitPts;
        this->energyPts = other.energyPts;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

std::string ClapTrap::getName() const { return (this->name); }
unsigned int    ClapTrap::getHitsPts() { return (this->energyPts); }
unsigned int    ClapTrap::getEnergyPts() { return (this->energyPts); }
unsigned int    ClapTrap::getAttackDamage() { return (this->attackDamage);}


void    ClapTrap::attack(const std::string& target)
{
    if (this->energyPts >= 1 && this->hitPts > 0)
    {
        std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;
        this->energyPts--;
    }
    else
    {
        if (this->energyPts < 1)
            std::cout << "ClapTrap " << this->getName() << " doesn't have enough energy points to attack target " << target << std::endl;
        else 
            std::cout << "ClapTrap " << this->getName() << " doesn't have enough hit points to attack target " << target << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPts <= 0)
        std::cout << "ClapTrap " << this->getName() << " can't take any more damage" << std::endl;
    else if (this->hitPts < amount)
    {
        std::cout << "ClapTrap " << this->getName() << " takes " << this->hitPts << " damage points" << std::endl;
        this->hitPts = 0;
    }
    else 
    {
        std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage points" << std::endl;
        this->hitPts -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPts >= 1)
    {
        std::cout << "ClapTrap " << this->getName() << " is repaired of " << amount << " hit points" << std::endl;
        this->hitPts += amount;
        this->energyPts--;
    }
    else
        std::cout << "ClapTrap " << this->getName() << " doesnt't have enough hit points to be repaired" << std::endl;
}

