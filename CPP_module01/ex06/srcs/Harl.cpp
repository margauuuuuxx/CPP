#include "../includes/Harl.class.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::debug( void ) { std::cout << "[ DEBUG ]\nThis is a really nice CPP exercise that Margaux has done !\n\t\033[37m(Please read these levels messages with humor 😛)\033[0m" << std::endl; }

void    Harl::info( void ) { std::cout << "[ INFO ]\nI cannot believe that this code is this short and so well written, I didn't study enough to understand it." << std::endl; }

void    Harl::warning( void ) { std::cout << "[ WARNING ]\nI think I deserve to understand this code perfectly, so I will ask my fellow student for extensive explanations. This is almost unbearable : I must know more." << std::endl; }

void    Harl::error( void ) { std::cout << "[ ERROR ]\nThis is propoerly unacceptable ! I want to know more about CPP immediately !" << std::endl; }

int Harl::getLevel(std::string level)
{
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
        if (levels[i] == level)
            return (i);
    return (-1);
}

void    Harl::complain(std::string level)
{
    int i = getLevel(level);
    switch(i)
    {
        case 0:
            debug();
            // fall through
        case 1:
            info();
            // fall through
        case 2:
            warning();
            // fall through 
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
