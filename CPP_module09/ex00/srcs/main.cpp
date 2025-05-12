#include "../includes/BitcoinExchange.class.hpp"

// command to decompress file : tar -xvzf <file>


// --> display # of the file * xhange rate in the data file 
int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
    {
        std::cerr << "\e[31mWrong number of arguments ..\e[0m" << std::endl;
        return (1);
    }

        parseFile(argv[1]);
        
    return (0);
}