#include "../includes/Brain.class.hpp"

Brain::Brain() { std::cout << "Brain constructor has been called" << std::endl; }

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor has been called" << std::endl;
    *this = other;
}

Brain&  Brain::operator = (const Brain &other)
{
    std::cout << "Brain copy assignment operator has been called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain() { std::cout << "Brain destructor has been called" << std::endl; }