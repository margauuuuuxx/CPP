#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include "Contact.class.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int contact_count;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    displayContacts();
        void    displayIndexContact();
};

#endif 