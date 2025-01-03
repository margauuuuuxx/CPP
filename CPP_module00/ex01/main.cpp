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
    if (argc < 2 ||
        (argv[1] && (std::string(argv[1]) != "ADD" && std::string(argv[1]) != "SEARCH" 
        && std::string(argv[1]) != "EXIT")))
    {
        std::cout << "Please enter a valid argument:\n\tADD / SEARCH /EXIT" << std::endl;
        return (1);
    }
    return (0);
}