#include "../includes/Bureaucrat.class.hpp"

int main()
{
    try 
    {
        Bureaucrat Marg("Marg", 22);
        std::cout << Marg << std::endl;

        Bureaucrat Corr("The FABULOUS Corrector", 1);
        std::cout << Corr << std::endl;

        Bureaucrat Zero("Zero", 0);
        std::cout << Zero << std::endl;

        // Bureaucrat TooMuch("Too much", 151);
        // std::cout << TooMuch << std::endl;

        // Corr.incrementGrade();

        Marg.decrementGrade();
        std::cout << Marg << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}