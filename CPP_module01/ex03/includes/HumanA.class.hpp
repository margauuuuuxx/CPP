#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include "Weapon.class.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weaponA;
    public:
        HumanA(std::string name, Weapon& weaponA); // *
        ~HumanA();
        void    attack();
};

#endif 

/*
    use of a ref to ensure that the class operates on the same object as the one passed to them rather than a copy
    -->>>>> if we pass Weapon by value it is implicitely taken as a copy, so any modifications made
    to the original object will not affect the copy stored in the class
    Weapon& weponA --> here weaponA is NOT A NEW object but a ref to an existing Weapon
*/