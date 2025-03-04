#include "../includes/Bureaucrat.class.hpp"
#include "../includes/Form.class.hpp"

int main()
{
    try 
    {
        Bureaucrat Marg("Marg", 22);
        std::cout << Marg << std::endl;
        std::cout << std::endl;

        Bureaucrat Corr("The FABULOUS Corrector", 1);
        std::cout << Corr << std::endl;
        std::cout << std::endl;

        Form f1("Form 1", 10, 16);
        std::cout << f1 << std::endl;

        // f1.beSigned(Corr);
        // std::cout << f1 << std::endl;

        Corr.signForm(f1);
        Marg.signForm(f1);

        // Form f2("Form 2", 15, 15);
        // f2.beSigned(Marg);

        // Form f3("Form 3", 15, -1);
        // Form f4("Form 4", 151, 2);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}