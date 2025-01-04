#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNbr;
        std::string darkestSecret;
    public:
        Contact();
        ~Contact();

        void    setFirstName(std::string firstName);
        void    setLastName(std::string lastName);
        void    setNickname(std::string nickName);
        void    setPhoneNbr(std::string phoneNbr);
        void    setDarkestSecret(std::string darkestSecret);

        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNbr();
        std::string getDarkestSecret();

        bool    validPhoneNumber(const std::string& phoneNbr);
};

#endif