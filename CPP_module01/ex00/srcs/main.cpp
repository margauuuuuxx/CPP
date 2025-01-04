#include "../includes/Zombie.class.hpp"

int main()
{
    std::cout << "Creating zombie by creating a new object of the class Zombie without arg" << std::endl;
    Zombie  test;
    test.announce();
    std::cout << std::endl;

    std::cout << "Creating zombie by creating a new object of the class Zombie with an arg" << std::endl;
    Zombie test2("Marg");
    test2.announce();
    std::cout << std::endl;

    std::cout << "Creating new zombie on the heap" << std::endl;
    Zombie  *test3 = newZombie("Heap");
    test3->announce();
    std::cout << std::endl;

    std::cout << "Creating new zombie on the stack with random chunk" << std::endl;
    randomChump("Chunky");
    std::cout << std::endl;

    std::cout << "Deleting the zombie created on the heap" << std::endl;
    delete(test3);
    std::cout << std::endl;

    return (0);
}