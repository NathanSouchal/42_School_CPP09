/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:42:26 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/30 14:18:03 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <cstring>
# include <fstream>
# include <cstdlib>

void    fill_data_base_map(std::map<std::string, float> &data_base);
void    convert_input(std::map<std::string, float> &data_base, char *fileName);
bool    check_first_line(std::string line);
bool    check_line(std::string line);
bool    check_value(std::string value);
bool    check_date(std::string date);
std::string find_closest_date(std::map<std::string, float> &data_base, std::string date);

#endif