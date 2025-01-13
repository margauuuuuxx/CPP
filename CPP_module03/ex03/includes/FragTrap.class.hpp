#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include "ClapTrap.class.hpp"

class FragTrap : public virtual ClapTrap
{
    public: 
        FragTrap();
        FragTrap(std:: string name);
        FragTrap(const FragTrap &other);
        FragTrap&   operator=(const FragTrap &other);
        ~FragTrap();

        void    highFivesGuys(void);
};

#endif