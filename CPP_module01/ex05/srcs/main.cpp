#include "../includes/Harl.class.hpp"

int main()
{
    Harl harl;
    std::cout << "Input = DEBUG\nouput:\t";
    harl.complain("DEBUG");
    std::cout << std::endl;

    std::cout << "Input = INFO\nouput:\t";
    harl.complain("INFO");
    std::cout << std::endl;

    std::cout << "Input = WARNING\nouput:\t";
    harl.complain("WARNING");
    std::cout << std::endl;

    std::cout << "Input = ERROR\nouput:\t";
    harl.complain("ERROR");
    std::cout << std::endl;

    std::cout << "Input = LOOOOL\nouput:\t";
    harl.complain("LOOOL");
    std::cout << std::endl;

    std::cout << "Input = ERROOOOR\nouput:\t";
    harl.complain("ERROOOOR");
    std::cout << std::endl;

    std::cout << "Input = error\nouput:\t";
    harl.complain("error");
    std::cout << std::endl;

    std::cout << "Input = \nouput:\t";
    harl.complain("");
    std::cout << std::endl;
}
