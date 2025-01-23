#include "../includes/ScavTrap.class.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
    std::cout << "Default ScavTrap constructor has been called" << std::endl;
    this->name = ("Default name");
    this->hitPts = 100;
    this->energyPts = 50;
    this->attackDamage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "String ScavTrap constructor has been called" << std::endl;
    this->hitPts = 100;
    this->energyPts = 50;
    this->attackDamage = 20; 
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor has been called" << std::endl;
    *this = other;
}

ScavTrap&   ScavTrap::operator = (const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator has been called" << std::endl;
    if (this != &other)
    {
        this->name = other.getName();
        this->hitPts = other.hitPts;
        this->energyPts = other.energyPts;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor has been called" << std::endl; }

void    ScavTrap::guardGate() { std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode" << std::endl; }

void    ScavTrap::attack(const std::string& target)
{
    if (this->energyPts >= 1 && this->hitPts > 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->attackDamage << " points of damage !" << std::endl;
        this->energyPts--;
    }
    else
    {
        if (this->energyPts < 1)
            std::cout << "ScavTrap " << this->getName() << " doesn't have enough energy points to attack target " << target << std::endl;
        else 
            std::cout << "Scavtrap " << this->getName() << " doesn't have enough hit points to attack target " << target << std::endl;
    }
}