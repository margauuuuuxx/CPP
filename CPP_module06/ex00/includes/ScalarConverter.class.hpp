/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:04:42 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 14:16:43 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <iostream>
#include <cctype>

#include "Utils.class.hpp"
#include "ConversionResults.class.hpp"

/*
  Non-satic methods require an instance of the class to be used, that's why we use static here  
*/

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();
    
  public:
    static void  Convert(const std::string);
};

#endif