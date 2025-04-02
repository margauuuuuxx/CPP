/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.class.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:10:34 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/02 12:26:39 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONRESULTS_CLASS_HPP
#define CONVERSIONRESULTS_CLASS_HPP

#include <iostream>

enum    TypeFlag 
{
  Impossible,
  Char,
  Int,
  Float,
  Double,
};

class   GetConversions 
{
    public:
        struct ConversionResult
        {
            void        *value;
            TypeFlag    type;
            
            ConversionResult(void *val, TypeFlag t);
            ~ConversionResult();
        };
        
        GetConversions();
        GetConversions(const GetConversions &other);
        GetConversions& operator=(const GetConversions &other);
        ~GetConversions();    
        
        ConversionResult    convertChar(const std::string str);
        ConversionResult    convertInt(const std::string &str);
        ConversionResult    convertFloat(const std::string str);
        ConversionResult    convertDouble(const std::string str);
};

#endif 
