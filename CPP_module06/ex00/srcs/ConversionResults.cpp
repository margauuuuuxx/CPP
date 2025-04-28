/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:23 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/28 16:43:04 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConversionResults.class.hpp"

GetConversions::ConversionResult::ConversionResult(void *val, TypeFlag t) : value(val), type(t) {}
GetConversions::ConversionResult::~ConversionResult()
{
    // if (type != Impossible && value != NULL)
    // {
    //     if (type == Char)
    //         delete (char *)value;
    //     else if (type == Int)
    //         delete (int *)value;
    //     else if (type == Float)
    //         delete (float *)value;
    //     else if (type == Double)
    //         delete (double *)value;
    // }
}

GetConversions::GetConversions() {}
GetConversions::GetConversions(const GetConversions &other) { *this = other; }
GetConversions& GetConversions::operator = (const GetConversions &other)
{
    (void)other;
    return (*this);
}
GetConversions::~GetConversions() {}

GetConversions::ConversionResult    GetConversions::convertChar(const std::string &str)
{
    std::stringstream ss(str);
    char    *result;
    int     value;
    
    if (str.length() == 1)
    {
        if (std::isprint(static_cast<unsigned char>(str[0])))
        {
            result = new char(str[0]);
            return (ConversionResult(result, Char));
        }
    }
    
    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    if (value < 0 || value > 127)
        return (ConversionResult((void *)"Impossible", Impossible));
    if (value < 32 || value == 127)
        return(ConversionResult((void *)"Non Displayable", NonDisplayable));
    result = new char(static_cast<char>(value));
    return (ConversionResult(result, Char));
}

GetConversions::ConversionResult    GetConversions::convertInt(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    int *result;

    if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])))
    {
        result = new int(static_cast<int>(str[0]));
        return (ConversionResult(result, Int));    
    }

    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    result = new int(value);
    return (ConversionResult(result, Int));
}

GetConversions::ConversionResult    GetConversions::convertFloat(const std::string &str)
{
    std::stringstream   ss(str);
    float   *result;
    float   value;

    result = NULL;
    if (str == "nan" || str == "nanf")
        return (ConversionResult(new float (NAN), Float));
    else if (str == "+inff" || str == "-inff" || str == "inff")
        return (ConversionResult(new float(str == "+inff" ? INFINITY : -INFINITY), Float));
    
    if (str.length() == 1)
        return(ConversionResult(new float(static_cast<float>(static_cast<int>(str[0]))), Float));

    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    result = new float(value);
    return (ConversionResult(result, Float));
}

GetConversions::ConversionResult    GetConversions::convertDouble(const std::string &str)
{
    std::stringstream   ss(str);
    double  value;

    if (str == "nan" || str == "nanf")
        return (ConversionResult(new double (NAN), Double));
    else if (str == "+inff" || str == "-inff" || str == "inff")
        return (ConversionResult(new double(str == "+inff" ? INFINITY : -INFINITY), Double));

    if (str.length() == 1)
        return(ConversionResult(new double(static_cast<double>(static_cast<int>(str[0]))), Double));

    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    return (ConversionResult(new double(value), Double));
}
