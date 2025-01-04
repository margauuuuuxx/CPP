#include "Contact.class.hpp"

Contact::Contact() { return; }

Contact::~Contact() { return; }

void    Contact::setFirstName(std::string firstName) { this->firstName = firstName; }
void    Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void    Contact::setNickname(std::string nickName) { this->nickName = nickName; }
void    Contact::setPhoneNbr(std::string phoneNbr) { this->phoneNbr = phoneNbr; }
void    Contact::setDarkestSecret (std::string darkestSecret) { this->darkestSecret = darkestSecret; }

std::string Contact::getFirstName() { return (firstName); } // implicitly referring to the attribue of the current object
std::string Contact::getLastName() { return (lastName); }
std::string Contact::getNickname() { return (nickName); }
std::string Contact::getPhoneNbr() { return (phoneNbr); }
std::string Contact::getDarkestSecret() { return (darkestSecret); }
 
bool    Contact::validPhoneNumber(const std::string& phoneNbr)
{
    for (size_t i = 0; i < phoneNbr.length(); i++)
    {
        if (!std::isdigit(phoneNbr[i]))
            return (false);
    }
    return (true);
}