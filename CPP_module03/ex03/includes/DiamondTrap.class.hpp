#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

#include "ScavTrap.class.hpp"
#include "FragTrap.class.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
    
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap&    operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void    whoAmI();
};

#endif