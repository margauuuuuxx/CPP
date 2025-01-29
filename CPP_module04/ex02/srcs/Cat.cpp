#include "../includes/Cat.class.hpp"

Cat::Cat() : Animal()
{ 
    std::cout << "Cat default constructor has been called" << std::endl; 
    type = "Cat";
    catBrain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor has been called" << std::endl;
    this->catBrain = new Brain();
    this->type = "Cat";
}

Cat&    Cat::operator = (const Cat &other)
{
    std::cout << "Cat copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat() 
{ 
    std::cout << "Cat Destructor has been called" << std::endl; 
    delete (this->catBrain);    
}

void    Cat::makeSound() const { std::cout << "Meow! Meow!" << std::endl; }