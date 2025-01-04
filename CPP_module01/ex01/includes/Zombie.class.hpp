#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <limits>

class   Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string name = "default name");
        ~Zombie();
        void    announce(void);
        void    setName(std::string name);
};

Zombie  *zombieHorde( int N, std::string name );

#endif 