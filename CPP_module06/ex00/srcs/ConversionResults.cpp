/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:23 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/03 16:26:00 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConversionResults.class.hpp"

// bool    charFlag = 1;
// bool    intFlag = 1;
// bool    floatFlag = 1;
// bool    doubleFlag = 1;

GetConversions::ConversionResult::ConversionResult(void *val, TypeFlag t) : value(val), type(t) {}
GetConversions::ConversionResult::~ConversionResult()
{
    if (type != Impossible && value != NULL)
    {
        if (type == Char)
            delete (char *)value;
        else if (type == Int)
            delete (int *)value;
        else if (type == Float)
            delete (float *)value;
        else if (type == Double)
            delete (double *)value;
    }
}

GetConversions::GetConversions() {}
GetConversions::GetConversions(const GetConversions &other) { *this = other; }
GetConversions& GetConversions::operator = (const GetConversions &other)
{
    (void)other;
    return (*this);
}
GetConversions::~GetConversions() {}

GetConversions::ConversionResult    GetConversions::convertInt(const std::string &str)
{
    //if (intFlag == 0)
        return (ConversionResult((void *)"Impossible", Impossible));
    try
    {
        size_t pos = 0;
        int *result = new int (2);
        //int *result = new int(std::stoi(str, &pos));
        if (pos != str.length())
        {
            delete result;
            return (ConversionResult((void *)"Impossible", Impossible));
        }
        return (ConversionResult(result, Int)); 
    }
    catch (const std::invalid_argument &)
    {
        return (ConversionResult((void *)"Impossible", Impossible));
    }
    catch (const std::out_of_range &)
    {
        return (ConversionResult((void *)"Impossible", Impossible));
    }
}