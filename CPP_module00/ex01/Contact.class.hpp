#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_nbr;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();

        void    setFirstName(std::string first_name);
        void    setLastName(std::string last_name);
        void    setNickname(std::string nickname);
        void    setPhoneNbr(std::string phone_nbr);
        void    setDarkestSecret(std::string darkest_secret);
        
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNbr();
        std::string getDarkestSecret();
};

#endif