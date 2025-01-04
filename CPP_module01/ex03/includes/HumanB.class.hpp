#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include "Weapon.class.hpp"

class HumanB
{
    private:
        Weapon* weaponB; // use of a ptr so it can be initialized after
        std::string name;
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon& weaponB);
};

#endif