/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/02 09:27:15 by nsouchal         ###   ########.fr       */
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

void    convert_input(std::map<std::string, float> &data_base, char *fileName)
{
    std::ifstream   data_file_stream(fileName);
    std::string     line;
    size_t          pipe_pos;
    float           value;
    std::string     date;
    std::string     date_data_base;
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
        if (check_line(line))
        {
            pipe_pos = line.find('|');
            date = line.substr(0, pipe_pos - 1);
            date_data_base = find_closest_date(data_base, date);
            value = strtof((line.substr(pipe_pos + 2)).c_str(), &end);
            std::cout << date << " => " << value << " = " << data_base[date_data_base] * value << std::endl;
        }
    }
    data_file_stream.close();
}

std::string find_closest_date(std::map<std::string, float> &data_base, std::string date)
{
   std::map<std::string, float>::iterator   it;
   
   it = data_base.lower_bound(date);
   if (it->first != date)
   {
        it--;
        return (it->first);
   }
   return (it->first);
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
    if (!check_value(line.substr(pos + 2)))
        return (false);
    return (true);
}

bool    check_value(std::string value)
{
    float   f_value;
    char    *end;
    
    f_value = strtof(value.c_str(), &end);
    if ((f_value == 0 && !(value.size() == 0 && value[0] == 0)) || *end != '\0')
    {
        std::cout << "Error: bad input => " << value << std::endl;
        return (false);
    }
    if (f_value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }
    if (f_value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
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
