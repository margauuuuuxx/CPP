#include "../includes/WrongCat.class.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor has been called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor has been called" << std::endl;
    *this = other;
}

WrongCat&   WrongCat::operator = (WrongCat const &other)
{
    std::cout << "WrongCat copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->type = other.getType();
    return (*this);
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor has been called" << std::endl; }

void    WrongCat::makeSound() const { std::cout << "WROOONG MIAOUW!" << std::endl; }