#include "../includes/Cat.class.hpp"
#include "../includes/Dog.class.hpp"
#include "../includes/WrongCat.class.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* Max = new Dog();
    const Animal* Domino = new Cat();

    std::cout << std::endl;

    std::cout << "Max type: " << Max->getType() << std::endl;
    std::cout << "\tSound: "; 
    Max->makeSound();
    std::cout << "Domino type: " << Domino->getType() << std::endl;
    std::cout << "\tSound: ";
    Domino->makeSound();
    std::cout<< "\tAnimal class sound: ";
    meta->makeSound();
    std::cout << std::endl;

    delete Domino;
    delete Max;
    delete meta;
    std::cout << std::endl;

    Animal animal;
    Dog Preums;
    Cat Dragibus;
    std::cout << std::endl;

    std::cout << "Animal sound: ";
    animal.makeSound();
    std::cout << "Preums sound: ";
    Preums.makeSound();
    std::cout << "Dragibus sound: ";
    Dragibus.makeSound();
    std::cout << std::endl;

    std::cout << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongCat* wrongcat = new WrongCat();
    const WrongAnimal *wrongg = new WrongCat();
    std::cout << std::endl;

    std::cout << "Wrong animal sound: ";
    wrong->makeSound();
    std::cout << "Wrong cat soud: ";
    wrongcat->makeSound();
    std::cout << "Wrongg sound: ";
    wrongg->makeSound();
    std::cout << std::endl;

    delete wrongcat;
    delete wrongg;
    delete wrong;
}