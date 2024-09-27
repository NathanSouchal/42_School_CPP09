/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:38 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/27 09:48:38 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::map<std::string, float> data_base;
        std::map<std::string, float> data_input;

        fill_data_base_map(data_base);
        std::cout << data_base["2012-10-17"] << std::endl;
        fill_data_file_map(data_input, argv[1]);
    }
    else
        std::cout << "Error: Bad arguments" << std::endl;
    return (0);
}