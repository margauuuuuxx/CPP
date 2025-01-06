#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() 
{ 
    contactCount = 0;
    for (int i = 0; i < 8; i++)
    {
        contacts[i].setFirstName("");
        contacts[i].setLastName("");
        contacts[i].setNickname("");
        contacts[i].setPhoneNbr("");
        contacts[i].setDarkestSecret("");
    }
}

PhoneBook::~PhoneBook() { return; }

void    PhoneBook::addContact()
{
    std::string input;
    Contact newContact;
    
    std::cout << "Enter first name : ";
    std::cin.ignore();
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cout << "Invalid input, please type ADD again if you would like to retry" << std::endl;
        return;
    }
    newContact.setFirstName(input);

    std::cout << "Enter last name : ";
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cout << "Invalid input, please type ADD again if you would like to retry" << std::endl;
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter nickname : ";
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cout << "Invalid input, please type ADD again if you would like to retry" << std::endl;
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter phone number : ";
    if (!std::getline(std::cin, input) || input.empty() || !(newContact.validPhoneNumber(input)))
    {
        std::cout << "Invalid input, please type ADD again if you would like to retry" << std::endl;
        return;
    }
    newContact.setPhoneNbr(input);

    std::cout << "Enter darkest secret : ";
    if (!std::getline(std::cin, input) || input.empty())
    {
        std::cout << "Invalid input, please type ADD again if you would like to retry" << std::endl;
        return;
    }
    newContact.setDarkestSecret(input);

    this->contacts[this->contactCount % 8] = newContact;
    if (this->contactCount < 8)
        std::cout << GREEN << "Contact added successfully" << RESET << std::endl;
    else 
        std::cout << "Phonebook is full ! Replacing the oldest contact ..." << std::endl;
    this->contactCount++;
}

static std::string  truncateString(const std::string& str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

bool    isNumeric(std::string str)
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (!std::isdigit(*it))
            return (false);
    }
    return (true);
}

void PhoneBook::display(const int &i)
{
        std::cout << std::setw(10) << std::right << i 
        << "|" << std::setw(10) << std::right << truncateString(contacts[i].getFirstName())
        << "|" << std::setw(10) << std::right << truncateString(contacts[i].getLastName())
        << "|" << std::setw(10) << std::right << truncateString(contacts[i].getNickname()) << std::endl;
}

void    PhoneBook::displayContacts()
{
    if (this->contactCount == 0)
    {
        std::cout << "No contacts to display" << std::endl;
        return ;
    }
    if (this->contactCount < 8)
         for (int i = 0; i < contactCount; i++)
            display(i);
    else 
        for (int i = 0; i < 8; i++)
            display(i);

    std::string input;
    std::cout << "What index would you like to see ? " << std::endl;
    std::cin.ignore();
    if (!std::getline(std::cin, input) || input.empty() || !isNumeric(input))
    {
        std::cout << "Invalid input, please type SEARCH again and then submit an index if you would like to retry" << std::endl;
        return;
    }
    try 
    {
        int index = std::atoi(input.c_str());
        if (index < 0 || index > (this->contactCount - 1))
            std::cout << "Invalid index, please provide a number between 0 and " << (this->contactCount - 1) << std::endl;
        else 
           display(index);
    }
    catch (const std::invalid_argument& e) { std::cout << "Invalid input, please type SEARCH again and then provide a number for the index" << std::endl; }
    catch (const std::out_of_range& e) { std::cout << "Invalid index, please type SEARCH again and then provide a number between 0 and " << (this->contactCount - 1) << std::endl; }
}
