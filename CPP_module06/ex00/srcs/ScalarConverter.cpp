/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:36:32 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 14:28:21 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

bool    charFlag;
bool    intFlag;
bool    floatFlag;
bool    doubleFlag;

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }
ScalarConverter&    ScalarConverter::operator = (const ScalarConverter &other)
{
    (void)other;
    return (*this);
}
ScalarConverter::~ScalarConverter() {}

void    initFlags()
{
    charFlag = 1;
    intFlag = 1;
    floatFlag = 1;
    doubleFlag = 1;
}

bool    nonDisplayable(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
        if (std::iscntrl(static_cast<unsigned char>(str[i])) 
            || !std::isprint(static_cast<unsigned char>(str[i])))
            return (1);
    return (0);
}

int isStr(const std::string& str)
{
    if (str == "nan" || str == "nanf"
        || str == "-inff" || str == "-inf"
        || str == "+inff" || str == "+inf")
    {
        charFlag = 0;
        intFlag = 0;
        return (0);
    }
    else if (str.length() > 1)
        return (1);
    return (0);
}

void parse(const std::string& str)
{
    // check si plusieurs lettres 
    if (isStr(str))
        Utils::errorExit("String provided ..");
    
    // check si lettre displayable 
    if (nonDisplayable(str))
        Utils::errorExit("Non displaybale character provided ..");
    
    // check en fct des case si c'est au dela de la limite
    
}

void    display(const std::string &str)
{
    std::cout << "char:\t";
    if (charFlag == 0)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << ConversionResults::charResult(str) << std::endl; 
}

void    ScalarConverter::Convert(const std::string str)
{
    initFlags();
    parse(str);
}