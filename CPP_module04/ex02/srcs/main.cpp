#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongCat.class.hpp"

#include <limits>

int main()
{
    int size;

    //Animal* animal = new Animal();

    size = 10;
    if (size < 0 || size > std::numeric_limits<int>::max())
        return (0);
    const Animal* Animals[size];
    for (int i = 0; i < size/2; i++)
        Animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        Animals[i] = new Cat();

    std::cout << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << "Animal number " << i + 1 << " of type: " << Animals[i]->getType() << std::endl << "\t";
        Animals[i]->makeSound();
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++)
        delete (Animals[i]);

    return 0;
}