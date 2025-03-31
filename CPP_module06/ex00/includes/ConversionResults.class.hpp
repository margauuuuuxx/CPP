/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConversionResults.class.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:10:34 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 14:31:23 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONRESULTS_CLASS_HPP
#define CONVERSIONRESULTS_CLASS_HPP

#include <iostream>

class   ConversionResults
{
    public:
        static void *charResult;
        static void *intResult;
        static void *floatResult;
        static void *doubleResult;

        static void    *convertChar(const std::string str);
        static void    *convertInt(const std::string &str);
        static void    *convertFloat(const std::string str);
        static void    *convertDouble(const std::string str);
};

#endif 
