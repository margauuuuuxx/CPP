#include "../includes/Harl.class.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void    Harl::debug() { std::cout << "This is a really nice CPP exercise that Margaux has done !\n\t\033[37m(Please read these levels messages with humor 😛)\033[0m" << std::endl; }

void    Harl::info() { std::cout << "I cannot believe that this code is this short and so well written, I didn't study enough to understand it." << std::endl; }

void    Harl::warning() { std::cout << "I think I deserve to understand this code perfectly, so I will ask my fellow student for extensive explanations. This is almost unbearable : I must know more." << std::endl; }

void    Harl::error() { std::cout << "This is propoerly unacceptable ! I want to know more about CPP immediately !" << std::endl; }

void    Harl::complain(std::string level)
{
    std::map<std::string, void (Harl::*)()> actions; // *
    actions.insert(std::make_pair("debug", &Harl::debug));
    actions.insert(std::make_pair("info", &Harl::info));
    actions.insert(std::make_pair("warning", &Harl::warning));
    actions.insert(std::make_pair("error", &Harl::error));
    std::map<std::string, void (Harl::*)()>::iterator it = actions.find(level); // **
    if (it != actions.end())
        (this->*(it->second))(); // ***
    else 
        std::cout << "\033[31m" << "Invalid level: " << level << "\033[0m" << std::endl;
}

/* *
    declaring a map named actions where :
        - map is a container that stores key-value pairs 
        - syntax: std::map<KeyType, ValueType>
            here KeyType is std::string & value type is a ptr to a fct void (Harll::*)()
        - void (Harll::*) ()
            --> void = the return type of the member fcts
            --> Harll::* = specifies that the ptr points to a member fct of Harl
            --> () = Harl takes no parameters 
        - actions = the var name of the map
*/

/* **
    seraching for a key in a map :
        - auto --> automatically deduce the type of it (we could have use std::map<std::string, void (Harl::*)()>::iterator instead)
        - find(level)   --> search for the given key level
                        --> if key is found: returns an iterator pointing to the matching pair
                                    not found: it=actions.end()
*/

/* ***
    call the appropriate member fct via its ptr
        - it->first = the key (thus level)
        - it->second = the value (thus the ptr to fct)
        - why this->* ?
            to deref a ptr to a fct and call it on the object pointed to by this 
*/