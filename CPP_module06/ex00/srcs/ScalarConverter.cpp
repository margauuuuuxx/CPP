/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:36:32 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/28 12:11:52 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"
#include "../includes/Globals.hpp"

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

void    setFlags(int a, int b, int c, int d)
{
    charFlag = a;
    intFlag = b;
    floatFlag = c;
    doubleFlag = d;
}

int isStr(const std::string& str) // return 1 if its string == more than 1 alphabetical char 
{
    size_t  start = 0;
    bool    hasDigit = 0;
    bool    hasDot = 0;
    char    lastSign = '\0';
    
    if (str == "nan" || str == "nanf"
        || str == "-inff" || str == "-inf"
        || str == "+inff" || str == "+inf")
    {
        charFlag = 0;
        intFlag = 0;
         return (0);
    }
    
    while (str[start] == '+' || str[start] == '-')  // CASE WHERE MISMATCH + / - 
     {
        if (lastSign != '\0' && str[start] != lastSign)
        {
            setFlags(0, 0, 0, 0);
            return (1);
        }
        lastSign = str[start];
        start++;
     }   
    if (start >= str.length() && start > 1) // only +/-
        {
            setFlags(0, 0, 0, 0);
            return (1);
        }
    
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

// 1 if the variable type is printable 
// void    initGlobals()
// {
//     charFlag = 1;
//     intFlag = 1;
//     floatFlag = 1;
//     doubleFlag = 1;
// }

void    ScalarConverter::Convert(const std::string str)
{
    // initGlobals();
    parse(str);
}

int main(int argc, char **argv)
{
    std::cout << "HELLOOOOO" << std::endl;
    (void)argc;
    if (argv[1])
    {
        std::cout << "Input: " << argv[1] << std::endl;
        parse(argv[1]);  
    }
    std::cout << "Char flag = " << charFlag << std::endl;
    std::cout << "Int flag = " << intFlag << std::endl;
    std::cout << "Float flag = " << floatFlag << std::endl;
    std::cout << "Double flag = " << doubleFlag << std::endl;
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