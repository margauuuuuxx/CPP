#include "../includes/Intern.class.hpp"

int main()
{
    try 
    {
        Intern i1;
        AForm *f1 = i1.makeForm("robotomy request", "Marg");
        AForm *f2 = i1.makeForm("Presidential Pardon Form", "Marg");
        AForm *f3 = i1.makeForm("shrubbery Creation", "Marg");
        AForm *f4 = i1.makeForm("shrubbery Creation", "Marg");
    
        delete f1;
        delete f2;
        delete f3;
        delete f4;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}