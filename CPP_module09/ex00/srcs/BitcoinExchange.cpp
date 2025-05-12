#include "../includes/BitcoinExchange.class.hpp"

// TO DO

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; } 
BitcoinExchange&    BitcoinExchange::operator = (const BitcoinExchange & other) 
{
    if (this != &other)
    {
        // TO DO
        std::cout << "LOL" << std::endl;
    }
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

// ***** PARSING FCTS *****

void    parseLine(std::string& line)
{
    std::istringstream  iss(line);
    std::string word;
    int wordCount;

    wordCount = 0;
    while (iss >> word)
        wordCount++;
    if (wordCount != 3)
    {
        std::cerr << "\e[31mError: line has "<< wordCount << " words ...\e[0m" << std::endl;
        return;
    }

}

void    parseFile(std::string str)
{
    std::ifstream   file(str.c_str());
    if (!file.is_open())
    {
        std::cerr << "\e[31mError: could not open the file ...\e[0m" << std::endl;
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "\e[31mError: file is empty ...\e[0m" << std::endl;
        file.close();
        return;
    }

    std::string line;
    while (std::getline(file, line))
        parseLine(line);

    file.close();
}