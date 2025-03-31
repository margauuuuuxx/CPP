/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:30:23 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 14:35:52 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ConversionResults.class.hpp"

bool    charFlag = 1;
bool    intFlag = 1;
bool    floatFlag = 1;
bool    doubleFlag = 1;


void    *ConversionResults::convertInt(const std::string &str)
{
    if (intFlag == 0)
        return ("Impossible");
    else 
        // convert the str into an int
}