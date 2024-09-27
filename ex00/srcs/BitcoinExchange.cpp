/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/27 13:25:01 by nsouchal         ###   ########.fr       */
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
        std::cout << "Error: data input file couldn't be opened" << std::endl;
        return ;
    }
    getline(data_file_stream, line);
    if (!check_first_line(line))
        return ;
    while (getline(data_file_stream, line))
    {
        check_line(line);
        quote_pos = line.find('|');
        data_file[line.substr(0, quote_pos - 1)] = strtof((line.substr(quote_pos + 2)).c_str(), &end);
    }
    data_file_stream.close();
}

bool    check_first_line(std::string line)
{
    if (line.compare("date | value"))
    {
        std::cout << "Error: bad format, title line => " << line << std::endl;
        return (false);
    }
    return (true);
}

bool    check_line(std::string line)
{
    size_t  pos;

    pos = line.find('|');
    if (!check_date(line.substr(0, pos - 1)))
    {
        std::cout << "Error: bad input => " << line.substr(0, pos - 1) << std::endl;
        return (false);
    }
    return (true);
}

bool    check_date(std::string date)
{
    std::string  year;
    std::string  month_str;
    long         month;
    std::string  day_str;
    long         day;
    size_t       pos_dash1;
    size_t       pos_dash2;
    char         *end;
    
    pos_dash1 = date.find('-');
    year = date.substr(0, pos_dash1);
    if (strtol(year.c_str(), &end, 10) < 2009 || strtol(year.c_str(), &end, 10) > 2022)
        return (false);
    pos_dash2 = (date.substr(pos_dash1 + 1)).find('-');
    month_str = date.substr(pos_dash1 + 1, pos_dash2);
    month = strtol(month_str.c_str(), &end, 10);
    if (month_str.size() != 2)
        return (false);
    if (!((month_str[0] == '0' && strtol(month_str.c_str() + 1, &end, 10) >= 1 && strtol(month_str.c_str() + 1, &end, 10) <= 9) \
    || (month >= 10 && month <= 12)))
        return (false);
    day_str = date.substr(pos_dash2 + pos_dash1 + 2).c_str();
    day = strtol(day_str.c_str(), &end, 10);
    if (day_str.size() != 2 || *end != '\0')
        return (false);
    if (day >= 1 && day <= 31)
    {
        if (day > 28 && month == 2)
            return (false);
        if (day == 31 && (month % 2 != 0 && month != 12 && month != 10 && month != 8))
            return (false);
    }
    else
        return (false);
    return (true);
}
