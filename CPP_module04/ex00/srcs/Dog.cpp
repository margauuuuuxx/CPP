#include "../includes/Dog.class.hpp"

Dog::Dog()
{ 
    std::cout << "Dog default constructor has been called" << std::endl; 
    type = "Dog";
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor has been called" << std::endl;
    *this = other;
}

Dog&    Dog::operator = (const Dog &other)
{
    std::cout << "Dog copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog() { std::cout << "Dog destructor has been called" << std::endl; }

void    Dog::makeSound() const { std::cout << "Woof! Woof!" << std::endl; }