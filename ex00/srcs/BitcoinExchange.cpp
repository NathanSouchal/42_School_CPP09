/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/26 15:42:51 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    fill_data_base_map(std::map<std::string, float> &data_base)
{
    std::ifstream   data_base_stream("data.csv");
    std::string     line;
    size_t          quote_pos;
    char            *end;
    
    if (!data_base_stream.is_open())
    {
        std::cout << "Error: data base file couldn't be opened" << std::endl;
        return ;
    }
    getline(data_base_stream, line);
    while (getline(data_base_stream, line))
    {
        quote_pos = line.find(',');
        data_base[line.substr(0, quote_pos)] = strtof((line.substr(quote_pos + 1)).c_str(), &end);
    }
    data_base_stream.close();
}

void    fill_data_file_map(std::map<std::string, float> &data_file, char *fileName)
{
    std::ifstream   data_file_stream(fileName);
    std::string     line;
    size_t          quote_pos;
    char            *end;
    
    if (!data_file_stream.is_open())
    {
        std::cout << "Error: data base file couldn't be opened" << std::endl;
        return ;
    }
    getline(data_file_stream, line);
    while (getline(data_file_stream, line))
    {
        quote_pos = line.find('|');
        data_file[line.substr(0, quote_pos - 1)] = strtof((line.substr(quote_pos + 2)).c_str(), &end);
    }
    data_file_stream.close();
}

