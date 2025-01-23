#include "../includes/FragTrap.class.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap constructor has been called" << std::endl;
    this->hitPts = 100;
    this->energyPts = 100;
    this->attackDamage = 30;
}   

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "String FragTap constructor has been called" << std::endl;
    this->hitPts = 100;
    this->energyPts = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTRap copy constructor has been called" << std::endl;
    *this = other;
}

FragTrap&   FragTrap::operator = (const FragTrap &other)
{
    if (this != &other)
    {
        this->name = other.getName();
        this->hitPts = other.hitPts;
        this->energyPts = other.energyPts;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
} 

FragTrap::~FragTrap() { std::cout << "FragTrap destructor has been called" << std::endl; }

void    FragTrap::highFivesGuys() { std::cout << this->name << " do a positive high five to you in the standard ouput" << std::endl; }