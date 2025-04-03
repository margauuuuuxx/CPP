/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:36:32 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/03 17:07:48 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }
ScalarConverter&    ScalarConverter::operator = (const ScalarConverter &other)
{
    (void)other;
    return (*this);
}
ScalarConverter::~ScalarConverter() {}

bool    nonDisplayable(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
        if (std::iscntrl(static_cast<unsigned char>(str[i])) 
            || !std::isprint(static_cast<unsigned char>(str[i])))
            return (1);
    return (0);
}

int isStr(const std::string& str) // return 1 if its string == more than 1 alphabetical char 
{
    size_t  start = 0;
    bool    hasDigit = 0;
    bool    hasDot = 0;
    
    if (str == "nan" || str == "nanf"
        || str == "-inff" || str == "-inf"
        || str == "+inff" || str == "+inf")
    {
        charFlag = 0;
        intFlag = 0;
        return (0);
    }
    if (str[start] == '+' || str[start] == '-')
    {
        start++;
        if (start >= str.length())
        {
            charFlag = 0;
            return (1);
        }  
    }
    if (str.length() > 1)
    {
        for (size_t i = start; i < str.length(); i++)
        {
            if (std::isdigit(str[i]))
                hasDigit = 1;
            else if (str[i] == '.')
            {
                if (hasDot)
                    return (1);
                hasDot = 1;
            }
            else if (str[i] == 'f' && i == str.length() - 1)
                return (0);
            // if (!std::isdigit(str[i]))
            // {
            //     charFlag = 0;
            //     return (1);
            // }
            else 
                return (1);
        }
    }
    return (0);
}

// void    set_flag(int a, int b, int c, int d)
// {
//     charFlag = a;
//     intFlag = b;
//     floatFlag = c;
//     doubleFlag = d;
// }

void parse(const std::string& str)
{
    if (str.empty())
        Utils::errorExit("Empty string provided ..");
    // check si plusieurs lettres 
    if (isStr(str))
        Utils::errorExit("String provided (more than 1 non-numerical character) ..");
    
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

void    initGlobals()
{
    charFlag = 1;
    intFlag = 1;
    floatFlag = 1;
    doubleFlag = 1;
}

void    ScalarConverter::Convert(const std::string str)
{
    initGlobals();
    parse(str);
}

int main()
{
    std::string str = "";
    std::cout << str << std::endl;
    parse(str);
}