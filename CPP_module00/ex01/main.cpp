/*
    3 commands : ADD / SEARCH / EXIT
        --> ADD displays field 1 by 1
        --> DISPLAY as a ;ine of 4 columns : index / fisrt/ last / nickname 
            each column must be 10 cher wide, separated by |, right aligned 
                if text longer then it must be truncated and the last displayable char must be set to '.'
            then asks for specific index to display 
        --> EXIT all contacts are lost 
    5 fields (no field can be empty) : first name / last name / nickname / phone number / darkest secret
    MAX 8 contacts 
*/

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(int argc, char **argv)
{
    (void)argv;

    if (argc > 1)
    {
        std::cout << "The program doesn't need any argument, please try again :P" << std::endl;
        exit (1);
    }

    PhoneBook phonebook;
    std::string input;
    while (1)
    {
        std::cout << "Choose an option: ADD / SEARCH / EXIT" << std::endl;
        std::cin >> input;
        if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.displayContacts();
        else if (input == "EXIT")
        {
            std::cout << PINK << "Exiting program, byeeeeee" << RESET << std::endl;
            break;
        }
        else
            std::cout << "Invalid command :(\nPlease choose from : ADD / SEARCH / EXIT" << std::endl;
    }

    return (0);
}