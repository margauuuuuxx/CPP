#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"

class ScavTrap : public ClapTrap // this is how we define inheritance *
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &other);
        ScavTrap&   operator=(const ScavTrap &other);
        ~ScavTrap();

        void    guardGate(void);
        void    attack(const std::string& target);
};

#endif

//  *in the 11 version we can use the using ClapTrap::Claptrap syntax for inheritance 