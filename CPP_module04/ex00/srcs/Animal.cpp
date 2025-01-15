#include "../includes/Animal.clas.hpp"

Animal::Animal() { std::cout << "Animal default constructor has been called" << std::endl; }
Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor has been called" << std::endl;
    *this = other;
}

Animal& Animal::operator = (const Animal &other)
{
    std::cout << "Animal copy assignment operator has been called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal() { std::cout << "Animal Destructor has been called" << std::endl; }

void    Animal::makeSound() const { std::cout << "Some generic animal sound!" << std::endl; }

std::string Animal::getType() const { return (this->type); }