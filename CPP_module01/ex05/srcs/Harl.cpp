#include "../includes/Harl.class.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::debug() { std::cout << "This is a really nice CPP exercise that Margaux has done !\n\t\033[37m(Please read these levels messages with humor 😛)\033[0m" << std::endl; }

void    Harl::info() { std::cout << "I cannot believe that this code is this short and so well written, I didn't study enough to understand it." << std::endl; }

void    Harl::warning() { std::cout << "I think I deserve to understand this code perfectly, so I will ask my fellow student for extensive explanations. This is almost unbearable : I must know more." << std::endl; }

void    Harl::error() { std::cout << "This is propoerly unacceptable ! I want to know more about CPP immediately !" << std::endl; }

void    Harl::complain(std::string level)
{
    fctPtr    actions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*actions[i])();
            return;
        }
    }
    std::cout << "\033[31m" << "Invalid level: " << level << "\033[0m" << std::endl;
}
