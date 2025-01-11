#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>

class ClapTrap
{
    protected:
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

        void    setName(std::string name);
        void    setHitPts(unsigned int hitPts);
        void    setEnergyPts(unsigned int energyPts);
        void    setAttackDamage(unsigned int attackDamage);

        std::string getName() const;
        unsigned int    getHitsPts();
        unsigned int    getEnergyPts();
        unsigned int    getAttackDamage();

        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

};

#endif 