#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>

class   Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string name = "default name");
        ~Zombie();
        void    announce(void);
};

Zombie* newZombie(std::string name); // heap allocation --> no automatic destruction
void    randomChunk(std::string name); // stack allocation --> automatic destruction

#endif 