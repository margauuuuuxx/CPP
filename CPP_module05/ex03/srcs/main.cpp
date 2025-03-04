#include "../includes/Intern.class.hpp"

int main()
{
    try 
    {
        Intern i1;
        i1.makeForm("robotomy request", "Marg");
        i1.makeForm("Presidential Pardon Form", "Marg");
        i1.makeForm("shrubbery Creation", "Marg");
        i1.makeForm("schrubbery Creation", "Marg");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}