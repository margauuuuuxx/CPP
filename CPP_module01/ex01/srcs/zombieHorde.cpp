#include "../includes/Zombie.class.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0 || N >= std::numeric_limits<int>::max())
        return (NULL);
    
    Zombie*  zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        std::cout << "Index : " << i << "\t";
        zombies[i].announce(); 
    }

    return (zombies);
}