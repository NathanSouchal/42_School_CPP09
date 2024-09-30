/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:38 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/30 09:45:50 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::map<std::string, float> data_base;

        fill_data_base_map(data_base);
        convert_input(data_base, argv[1]);
    }
    else
        std::cout << "Error: Bad arguments" << std::endl;
    return (0);
}