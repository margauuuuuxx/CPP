/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marlonco <marlonco@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:15:29 by marlonco          #+#    #+#             */
/*   Updated: 2025/04/28 17:40:50 by marlonco         ###   ########.fr       */
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

    // QUID ++++---- ???
}