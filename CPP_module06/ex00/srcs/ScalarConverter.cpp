/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:36:32 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/02 12:31:13 by marlonco         ###   ########.fr       */
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

std::ostream    &operator<<(std::ostream &os, const GetConversions::ConversionResult &result)
{
    switch (result.type)
    {
        case Impossible:
            os << "Impossible";
            break;
            
        case Char:
            os << "'" << *(char *)result.value << "'";
            delete (char *)result.value;
            break;
        
        case Int:
            os << *(int *)result.value;
            delete (int *)result.value;
            break;
        
        case Float:
            os << *(float *)result.value << "f";
            delete (float *)result.value;
            break;

        case Double:
            os << *(double *)result.value;
            delete (double *)result.value;
            break;
    }
    return (os);
}

void    display(const std::string &str)
{
    GetConversions converter;
    // std::cout << "char:\t" << std:;endl;
    std::cout << "int:\t" << converter.convertInt(str) << std::endl;
}

void    ScalarConverter::Convert(const std::string str)
{
    initFlags();
    parse(str);
}