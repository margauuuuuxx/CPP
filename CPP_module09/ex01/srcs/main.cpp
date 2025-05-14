#include "../includes/RPN.class.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\e[31mError: Wrong number of arguments ..\e[0m" << std::endl;
        return (1);
    }

    try {
        RPN data(argv[1]);
        std::cout << data.caluculate() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}