#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib> // for exit fct
#include "Contact.class.hpp"

#define PINK    "\033[1;38;5;213m"
#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m" 

class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    displayContacts();
        void    display(const int &i);
};

#endif 