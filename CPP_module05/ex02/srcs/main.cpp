#include "../includes/Bureaucrat.class.hpp"
#include "../includes/PresidentialPardonForm.class.hpp"
#include "../includes/RobotomyRequestForm.class.hpp"
#include "../includes/ShrubberyCreationForm.class.hpp"

int main()
{
    try 
    {
        Bureaucrat Marg("Marg", 73);
        std::cout << Marg << std::endl;
        Bureaucrat Corr("The FABULOUS Corrector", 1);
        std::cout << Corr << std::endl;
        std::cout << std::endl;

        PresidentialPardonForm ppf("ppf");
        RobotomyRequestForm rrf("rrf");
        SchrubberyCreationForm scf("scf");

        Corr.signForm(ppf);
        Corr.executeForm(ppf);
        std::cout << std::endl;

        Marg.signForm(rrf);
        Corr.signForm(rrf);
        std::cout << std::endl;

        // Marg.executeForm(rrf);
        // std::cout << std::endl;

        Marg.signForm(scf);
        Corr.executeForm(scf);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}