#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string     name;
        unsigned int    hitPts;
        unsigned int    energyPts;
        unsigned int    attackDamage;
    
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap&  operator = (const ClapTrap& other);

        std::string getName() const;
        unsigned int    getHitsPts();
        unsigned int    getEnergyPts();
        unsigned int    getAttackDamage();

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

};

#endif 