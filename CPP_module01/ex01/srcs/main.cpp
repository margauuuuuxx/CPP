#include "../includes/Zombie.class.hpp"

int main()
{
    // std::cout << "Creating a horde of zombie of size N = 0" << std::endl;
    // zombieHorde(0, "Marg");
    // std::cout << std::endl;

    // std::cout << "Creating a horde of zombie of size N = 1" << std::endl;
    // zombieHorde(1, "Marg");
    // std::cout << std::endl;

    std::cout << "Creating a horde of zombie of size N = 5 with no name" << std::endl;
    Zombie *zombies = zombieHorde(5, "");
    for (int i = 0; i < 5; i++)
        zombies[i].~Zombie();
    operator delete[](zombies);
    std::cout << std::endl;

    std::cout << "Creating a horde of zombie of size N = 5" << std::endl;
    Zombie *horde = zombieHorde(5, "Marg");
    std::cout << "Deleting all the zombie created on the heap" << std::endl;
    for (int i = 0; i < 5; i++)
        horde[i].~Zombie();
    operator delete[](horde);
    std::cout << std::endl;

    return (0);
}