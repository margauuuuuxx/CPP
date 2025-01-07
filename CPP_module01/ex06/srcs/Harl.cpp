#include "../includes/Harl.class.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::debug() { std::cout << "[ DEBUG ]\nThis is a really nice CPP exercise that Margaux has done !\n\t\033[37m(Please read these levels messages with humor 😛)\033[0m" << std::endl; }

void    Harl::info() { std::cout << "[ INFO ]\nI cannot believe that this code is this short and so well written, I didn't study enough to understand it." << std::endl; }

void    Harl::warning() { std::cout << "[ WARNING ]\nI think I deserve to understand this code perfectly, so I will ask my fellow student for extensive explanations. This is almost unbearable : I must know more." << std::endl; }

void    Harl::error() { std::cout << "[ ERROR ]\nThis is propoerly unacceptable ! I want to know more about CPP immediately !" << std::endl; }

int Harl::getLevel(std::string level)
{
    std::map<std::string, int> levels;
    levels.insert(std::make_pair("DEBUG", 0));
    levels.insert(std::make_pair("INFO", 1));
    levels.insert(std::make_pair("WARNING", 2));
    levels.insert(std::make_pair("ERROR", 3));
    std::map<std::string, int>::iterator it = levels.find(level);
    if (it != levels.end())
        return (it->second);
    return (-1);
}

void    Harl::complain(std::string level)
{
    int i = getLevel(level);
    switch(i)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
