/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:38 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/26 15:42:24 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    std::map<std::string, float> data_base;
    std::map<std::string, float> data_input;

    fill_data_base_map(data_base);
    std::cout << data_base["2012-10-17"] << std::endl;
    return (0);
}