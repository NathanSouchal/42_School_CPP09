/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:42:26 by nsouchal          #+#    #+#             */
/*   Updated: 2024/09/26 15:38:23 by nsouchal         ###   ########.fr       */
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
void    fill_data_file_map(std::map<std::string, float> &data_file, char *fileName);

#endif