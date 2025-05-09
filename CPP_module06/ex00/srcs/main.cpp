/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:15:29 by marlonco          #+#    #+#             */
/*   Updated: 2025/05/09 10:54:05 by marlonco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 2)
        ScalarConverter::Convert(argv[1]);
    else
        ScalarConverter::errorExit("Too many or too little arguments provided ..");
}