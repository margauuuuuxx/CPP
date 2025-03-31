/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:21:50 by marlonco          #+#    #+#             */
/*   Updated: 2025/03/31 12:35:40 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.class.hpp"

Utils::Utils() {}

Utils::Utils(const Utils &other) { *this = other; }

Utils&  Utils::operator = (const Utils &other) 
{ 
    (void)other;
    return (*this); 
}

Utils::~Utils() {}

void    Utils::errorExit(const std::string str)
{
    std::cout << RED << str << RESET << std::endl;
    exit(1);
}