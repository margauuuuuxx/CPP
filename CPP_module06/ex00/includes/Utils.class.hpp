/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:19:47 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 12:35:29 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CLASS_HPP
# define UTILS_CLASS_HPP

#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

class Utils
{
    private: 
        Utils();
        Utils(const Utils &other);
        Utils& operator=(const Utils &other);
        ~Utils();

    public:
        static void errorExit(const std::string);
};

#endif 