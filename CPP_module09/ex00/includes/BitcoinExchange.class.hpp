#ifndef BITCOINEXCHANGE_CLASS_HPP
#define BITCOINEXCHANGE_CLASS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
    private:

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


};

void    parseFile(std::string str);

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