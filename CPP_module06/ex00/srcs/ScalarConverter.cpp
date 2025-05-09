/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:36:32 by marlonco          #+#    #+#             */
/*   Updated: 2025/05/09 11:19:05 by marlonco         ###   ########.fr       */
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

void    ScalarConverter::errorExit(const std::string str)
{
    std::cout << RED << str << RESET << std::endl;
    exit(1);
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
    size_t  start = 0;
    bool    hasDigit = 0;
    bool    hasDot = 0;
    char    lastSign = '\0';
    
    if (str == "nan" || str == "nanf"
        || str == "-inff" || str == "-inff"
        || str == "+inff" || str == "+inff"
        || str == "inff")
         return (0);
    
    while (str[start] == '+' || str[start] == '-') 
     {
        if (lastSign != '\0' && str[start] != lastSign)
            return (1);
        lastSign = str[start];
        start++;
     }   
    if (start >= str.length() && start > 1)
            return (1);
    
    if (str.length() > 1)
    {
        for (size_t i = start; i < str.length(); i++)
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
            else 
                return (1);
        if (!hasDigit)
            return (1);
    }
    return (0);
}

void parse(const std::string& str)
{
    if (str.empty())
        ScalarConverter::errorExit("Empty string provided ..");
        
    if (isStr(str))
        ScalarConverter::errorExit("String provided (more than 1 non-numerical character) ..");
    
    if (nonDisplayable(str))
        ScalarConverter::errorExit("Non displaybale character provided ..");
}

std::ostream    &operator<<(std::ostream &os, const GetConversions::ConversionResult &result)
{
    switch (result.type)
    {
        case Impossible:
            os << "Impossible";
            break;
            
        case NonDisplayable:
            os << "Non displayable";
            break;

        case Limit:
            os << "Not between variable type limits";
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
            if (static_cast<float>(static_cast<int>(*(float *)result.value)) == *(float *)result.value)
                os << *(float *)result.value << ".0f";
            else 
                os << *(float *)result.value << "f";
            delete (float *)result.value;
            break;

        case Double:
            if (static_cast<double>(static_cast<int>(*(double *)result.value)) == *(double *)result.value)
                os << *(double *)result.value << ".0";
            else
                os << *(double *)result.value;
            delete (double *)result.value;
            break;
    }
    return (os);
}

void    ScalarConverter::Convert(const std::string str)
{
    std::string s;
    GetConversions  converter;
    
    parse(str);

    s = str;
    if (s.length() > 1 && s[s.length() - 1] == 'f' 
            && s != "inff" && s != "-inff" && s != "+inff"
            && s != "nanf")
        s = s.substr(0, s.length() - 1);
        
    GetConversions::ConversionResult charResult = converter.convertChar(s);
    GetConversions::ConversionResult intResult = converter.convertInt(s);
    GetConversions::ConversionResult floatResult = converter.convertFloat(s);
    GetConversions::ConversionResult doubleResult = converter.convertDouble(s);

    std::cout << "char:\t" << charResult << std::endl;
    std::cout << "int:\t" << intResult << std::endl;
    std::cout << "float:\t" << floatResult << std::endl;
    std::cout << "double:\t" << doubleResult << std::endl;
}

/*
    PARSING TEST: 
    - empty string (""): OKK
    - single letter: OKK
    - int [32 ; 126] (displayable chars) : OKK
    - int non displayable : !!!!!!!!
    - float displyable : OKK
    - float non displayabe : !!!!!!
    - float avec 2+ f : OKK
    - float avec 2+ . : OKKK
    - double displayable : OKK
    - double qui termine par un . : !!!!!!!!
    - double non displayable : !!!!!!
    - +(s) chiffre : OKKK
    -(s) chiffre :
    - +- mismatched + chiffre : !!!!!!!!
    - juste +/- : OKKK
    - juste +/-s : OKKKKK
*/