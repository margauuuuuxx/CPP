#include "../includes/Zombie.class.hpp"

void    randomChunk(std::string name)
{
    Zombie  newZombie(name);
    newZombie.announce();
}