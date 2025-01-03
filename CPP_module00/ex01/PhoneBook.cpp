#include "PhoneBook.class.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    return;
}

PhoneBook::~PhoneBook() { return; }

void    PhoneBook::addContact()
{
    std::string input;

    if (contact_count >= 8)
        contact_count = 0;
    
    std::cout << "Enter first name :";
    std::cin >> input;
    if (std::cin.eof())
        return ;
}

void    PhoneBook::displayContacts()
{

}

void    PhoneBook::displayIndexContact()
{

}