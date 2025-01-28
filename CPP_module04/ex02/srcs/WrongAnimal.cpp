#include "../includes/WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor has been called" << std::endl;
    this->type = "WRONG";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
    std::cout << "WrongAnimal copy constructor has been called" << std::endl;
    *this = other;
}

WrongAnimal&    WrongAnimal::operator = (WrongAnimal const &other)
{
    if (this != &other)
        this->type = other.getType();
    return (*this);
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

void    WrongAnimal::makeSound() const { std::cout << "MAKING WRONG SOUNDS" << std::endl; }
std::string WrongAnimal::getType() const { return(this->type); }