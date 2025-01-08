#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include "Weapon.class.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weaponB; // use of a ptr so it can be initialized after
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon& weaponB);
};

#endif