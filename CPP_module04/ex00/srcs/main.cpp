#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
    const Animal* meta = new Animal();
    //const Animal* j = new Dog();
    const Animal* Dragi = new Cat();
    const WrongAnimal* Wrong = new WrongAnimal();
    const WrongAnimal* Catou = new WrongCat();

    std::cout << std::endl;

    //std::cout << j->getType() << " " << std::endl;
    std::cout << meta->getType() << std::endl;
    std::cout << Dragi->getType() << " " << std::endl;
    std::cout << Wrong->getType() << std::endl;
    std::cout << Catou->getType() << std::endl;
    meta->makeSound();
    Dragi->makeSound(); //will output the cat sound!
    //j->makeSound();
    Wrong->makeSound();
    Catou->makeSound();

    std::cout << std::endl;

    delete (meta);
    delete (Dragi);
    delete (Wrong);
    delete (Catou);
    return 0;
}