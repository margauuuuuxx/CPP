#include "../includes/Harl.class.hpp"

int main()
{
    Harl harl;
    std::cout << "Input = debug\nouput:\t";
    harl.complain("debug");
    std::cout << std::endl;

    std::cout << "Input = info\nouput:\t";
    harl.complain("info");
    std::cout << std::endl;

    std::cout << "Input = warning\nouput:\t";
    harl.complain("warning");
    std::cout << std::endl;

    std::cout << "Input = error\nouput:\t";
    harl.complain("error");
    std::cout << std::endl;

    std::cout << "Input = LOOOOL\nouput:\t";
    harl.complain("LOOOL");
    std::cout << std::endl;

    std::cout << "Input = errorrrr\nouput:\t";
    harl.complain("errorrrr");
    std::cout << std::endl;

    std::cout << "Input = \nouput:\t";
    harl.complain("");
    std::cout << std::endl;
}
