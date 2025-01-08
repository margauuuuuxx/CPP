#include "../includes/Zombie.class.hpp"

int main()
{
    std::cout << "Creating a horde of zombie of size N = 5 with no name" << std::endl;
    Zombie *zombies = zombieHorde(5, "");
    delete[](zombies); // destructor is called automatially when using delete
    std::cout << std::endl;

    std::cout << "Creating a horde of zombie of size N = 5" << std::endl;
    Zombie *horde = zombieHorde(5, "Marg");
    std::cout << "Deleting all the zombie created on the heap" << std::endl;
    delete[](horde);
    std::cout << std::endl;

    std::cout << "Creating a horde of zombie of size N = 0" << std::endl;
    Zombie *horde2 = zombieHorde(0, "Marg");
    if (horde2 != NULL)
    {
        horde2->announce();
    }
    else 
        std::cout << "No zombies created because N = 0" << std::endl;
    std::cout << std::endl;

    std::cout << "Creating a horde of zombie of size N = -100" << std::endl;
    Zombie *horde3 = zombieHorde(-100, "Marg");
    if (horde3 != NULL)
    {
        horde3->announce();
    }
    else 
        std::cout << "No zombies created because N is negative" << std::endl;

    return (0);
}