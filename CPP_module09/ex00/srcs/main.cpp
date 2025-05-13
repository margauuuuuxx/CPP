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

    BitcoinExchange btc;
    
    std::ifstream   dataFile("./data.csv");
    if (!dataFile)
    {
        std::cerr << "\e[31mError: failed to open data.csv ..\e[0m" << std::endl;
        return (1);
    }
    btc.parseFile(dataFile, DATA_MAP);

    {
        std::cerr << "\e[31mError: failed to open " << argv[1] << "..\e[0m" << std::endl;
        return (1);
    }
    std::ifstream   file(argv[1]);
    btc.parseFile(file, VALUE_MAP);


    std::multimap<std::string, float> map = btc.getValueMap();
    std::cout << "***** VALUE MAP *****" << std::endl;
    std::map<std::string, float>::iterator it;
    for (it = map.begin(); it != map.end(); ++it)
        std::cout << "Key = " << it->first << "; value = " << it->second << std::endl; 
        
    return (0);
}