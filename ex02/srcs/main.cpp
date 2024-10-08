/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:03:57 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/08 14:28:50 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMeVector vecClass;
    PmergeMeDeque  dequeClass;
    VECTOR         unsorted_vec;
    VECTOR         sorted_vec;
    DEQUE          unsorted_deq;
    DEQUE          sorted_deq;
    double         time_vec;
    double         time_deq;
    
    if (argc < 2)
    {
        std::cerr << "Error: please enter at least two numbers" << std::endl;
        return (1);
    }
    try
    {
        clock_t start = clock();
        unsorted_vec = vecClass.parseSequence(argv + 1);
        sorted_vec = vecClass.algo(unsorted_vec);
        clock_t end = clock();
        time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        start = clock();
        unsorted_deq = dequeClass.parseSequence(argv + 1);
        sorted_deq = dequeClass.algo(unsorted_deq);
        end = clock();
        time_deq = static_cast<double>(end - start) / CLOCKS_PER_SEC;
        std::sort(unsorted_vec.begin(), unsorted_vec.end());
        if (sorted_vec != unsorted_vec)
            std::cout << "Error: sequence is not sorted using vector" << std::endl;
        std::sort(unsorted_deq.begin(), unsorted_deq.end());
        if (sorted_deq != unsorted_deq)
            std::cout << "Error: sequence is not sorted using deque" << std::endl;
        std::cout << "Before: ";
        printContainer(unsorted_vec);
        std::cout << "After: ";
        printContainer(sorted_vec);
        std::cout << "Time to process a range of " << unsorted_vec.size() \
        << " elements with std::vector: " << time_vec << " sec" << std::endl;
        std::cout << "Time to process a range of " << unsorted_deq.size() \
        << " elements with std::deque: " << time_deq << " sec" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}