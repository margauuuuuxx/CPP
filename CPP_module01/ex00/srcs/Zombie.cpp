#include "../includes/Zombie.class.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
        std::cout << "Zombie named " << this->name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie named " << this->name << " has been destroyed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}