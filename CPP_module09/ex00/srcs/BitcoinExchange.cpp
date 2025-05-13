#include "../includes/BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; } 
BitcoinExchange&    BitcoinExchange::operator = (const BitcoinExchange & other) 
{
    if (this != &other)
        this->_dataMap = other._dataMap;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}

// ***** GETTERS *****

const std::map<std::string, float>&    BitcoinExchange::getDataMap() const { return (this->_dataMap); }

// ***** PARSING FCTS *****

bool    parseValue(std::string str)
{
    std::stringstream ss(str);
    float val;

    ss >> val;
    if (ss.fail() || !ss.eof())
        return (1);

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

void    BitcoinExchange::parseLineData(std::string &line)
{
    std::string::size_type  commaPos = line.find(',');
    std::string date = line.substr(0, commaPos);
    std::string valueStr = line.substr(commaPos + 1);
    float value = std::atof(valueStr.c_str());
    std::cout << "Data date = " << date << " data value = " << value << std::endl;
    _dataMap[date] = value;
}

void    BitcoinExchange::parseLine(std::string& line)
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

    float value = std::atof(third.c_str());
    std::map<std::string, float>::const_iterator    it = _dataMap.find(first);
    if (it == _dataMap.end())
    {
        it = _dataMap.upper_bound(first);
        if (it == _dataMap.begin())
        {
            std::cerr << "\e[31mError: no earlier exchange rate available for " << first << "\e[0m" << std::endl;
            return;
        }
        --it;
    }
    float   result = value * it->second;
    std::cout << first << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::parseFile(std::ifstream& file, MapMode mode)
{
    if (!file.is_open())
    {
        std::cerr << "\e[31mError: could not open the file ...\e[0m" << std::endl;
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "\e[31mError: file is empty ...\e[0m" << std::endl;
        return;
    }

    std::string line;
    if (std::getline(file, line))
    {
        if (line != "date | value" && line != "date,exchange_rate")
        {
            std::cerr << "\e[31mError: wrong file header ...\e[0m" << std::endl;
            return;
        }
    }
    while (std::getline(file, line))
        if (mode == DATA_MAP)
            parseLineData(line);
        else
            parseLine(line);
}
