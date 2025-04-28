/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:04:42 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/28 17:19:02 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

#include "ConversionResults.class.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

// Non-satic methods require an instance of the class to be used, that's why we use static here  

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();
    
  public:
    static void  Convert(const std::string);
    static void errorExit(const std::string);
};

#endif