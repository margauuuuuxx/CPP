/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:23 by marlonco          #+#    #+#             */
/*   Updated: 2025/05/09 11:19:29 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConversionResults.class.hpp"

GetConversions::ConversionResult::ConversionResult(void *val, TypeFlag t) : value(val), type(t) {}
GetConversions::ConversionResult::~ConversionResult() {}
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
    char    *result;
    
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
    {
        if (std::isprint(static_cast<unsigned char>(str[0])))
        {
            result = new char(str[0]);
            return (ConversionResult(result, Char));
        }
        return (ConversionResult((void *)"Non Displayable", NonDisplayable));
    }
    
    std::stringstream ss(str);
    double  value;
    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    int ivalue = static_cast<int>(value);
    if (ivalue < 0 || ivalue > 127)
        return (ConversionResult((void *)"Impossible", Impossible));
    if (ivalue < 32 || ivalue == 127)
        return(ConversionResult((void *)"Non Displayable", NonDisplayable));
    result = new char(static_cast<char>(value));
    return (ConversionResult(result, Char));
}

GetConversions::ConversionResult    GetConversions::convertInt(const std::string &str)
{
    std::stringstream ss(str);
    int     value;
    double  dvalue;

    if (str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])) && !std::isdigit(static_cast<unsigned char>(str[0])))
        return (ConversionResult(new int(static_cast<int>(str[0])), Int));    

    ss >> dvalue;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    if (std::isnan(dvalue) || std::isinf(dvalue))
        return (ConversionResult((void *)"Impossible", Impossible));
    if (dvalue > static_cast<double>(INT_MAX) || dvalue < static_cast<double>(INT_MIN))
        return (ConversionResult((void *)"Not between variable type limits", Limit));

    value = static_cast<int>(dvalue);
    return (ConversionResult(new int(value), Int));
}

GetConversions::ConversionResult    GetConversions::convertFloat(const std::string &str)
{
    std::stringstream   ss(str);
    float   value;

    if (str == "nan" || str == "nanf")
        return (ConversionResult(new float (NAN), Float));
    else if (str == "+inff" || str == "-inff" || str == "inff")
        return (ConversionResult(new float(str == "+inff" ? INFINITY : -INFINITY), Float));
    
    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        return(ConversionResult(new float(static_cast<float>(static_cast<int>(str[0]))), Float));

    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    if (value > FLT_MAX || value < -FLT_MAX)
        return (ConversionResult((void *)"Not between variable type limits", Limit)); 
    return (ConversionResult(new float(value), Float));
}

GetConversions::ConversionResult    GetConversions::convertDouble(const std::string &str)
{
    std::stringstream   ss(str);
    double  value;

    if (str == "nan" || str == "nanf")
        return (ConversionResult(new double (NAN), Double));
    else if (str == "+inff" || str == "-inff" || str == "inff")
        return (ConversionResult(new double(str == "+inff" ? INFINITY : -INFINITY), Double));

    if (str.length() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
        return(ConversionResult(new double(static_cast<double>(static_cast<int>(str[0]))), Double));

    ss >> value;
    if (ss.fail() || !ss.eof())
        return (ConversionResult((void *)"Impossible", Impossible));
    if (value > DBL_MAX || value < -DBL_MAX)
        return (ConversionResult((void *)"Not between variable type limits", Limit));
    return (ConversionResult(new double(value), Double));
}
