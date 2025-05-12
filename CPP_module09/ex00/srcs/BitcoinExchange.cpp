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

bool    parseValue(std::string str)
{
    bool    hasDot = 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '.')
        {
            if (hasDot || i == 0 || i == str.length() - 1)
                return (1);
            hasDot = 1;
        }
        else if (!std::isdigit(str[i]))
            return (1);
    }

    int value = std::atoi(str.c_str());
    if (value < 0 || value > 1000)
        return (1);

    return (0);
}

bool    parseDate(std::string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (1);
    
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return (1);
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    if (month > 12 || month < 1)
        return (1);
    int year = std::atoi(date.substr(0, 4).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month == 2 && ((year % 4 == 0 &&  year % 100 != 0) || year % 400 == 0))
        return (day >= 1 && day <= 29);
    if (day < 1 || day > gDaysInMonth[month])
        return (1);
    
    return (0);
}

void    parseLine(std::string& line)
{
    std::istringstream  iss(line);
    std::string word;
    std::string first, second, third;

    if (!(iss >> first >> second >> third))
    {
        std::cerr << "\e[31mError: line has less than 3 words ...\e[0m" << std::endl;
        return;
    }

    std::string extra;
    if (iss >> extra)
    {
        std::cerr << "\e[31mError: line has more than 3 words ...\e[0m" << std::endl;
        return;
    }

    if (parseDate(first) || parseValue(third) || second != "|")
    {
        std::cerr << "\e[31mError: parsing of the line ...\e[0m" << std::endl;
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
    if (std::getline(file, line))
    {
        if (line != "date | value")
        {
            std::cerr << "\e[31mError: expected header 'date | value' ...\e[0m" << std::endl;
            file.close();
            return;
        }
    }
    while (std::getline(file, line))
        parseLine(line);

    file.close();
}