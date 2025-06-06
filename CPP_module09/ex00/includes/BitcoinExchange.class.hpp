#ifndef BITCOINEXCHANGE_CLASS_HPP
#define BITCOINEXCHANGE_CLASS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

enum MapMode
{
    VALUE_MAP,
    DATA_MAP
};

class BitcoinExchange
{
    private:
        std::map<std::string, float>    _dataMap;

        void    parseLine(std::string &line);
        void    parseLineData(std::string &line);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        void parseFile(std::ifstream& file, MapMode mode);
        const std::map<std::string, float>&    getDataMap() const;
};


static const int    gDaysInMonth[13] = {
    0,
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31
};


#endif