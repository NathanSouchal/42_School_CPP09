/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:03:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/03 14:32:52 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMeVector vecClass;
    VECTOR         unsorted_seq;
    VECTOR         sorted_seq;
    
    if (argc < 2)
    {
        std::cerr << "Error: please enter at least two numbers" << std::endl;
        return (1);
    }
    try
    {
        unsorted_seq = vecClass.parseSequence(argv + 1);
        printContainer(unsorted_seq);
        sorted_seq = vecClass.algo(unsorted_seq);
        printContainer(sorted_seq);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}