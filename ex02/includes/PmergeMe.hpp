/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:32 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/08 14:24:38 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <cstring>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <algorithm>
# include <ctime>

typedef std::vector<std::pair<long, long> > VECTOR_PAIRS;
typedef std::vector<long> VECTOR;
typedef std::deque<long> DEQUE;
typedef std::deque<std::pair<long, long> > DEQUE_PAIRS;

class ARG_ERROR : public std::exception
{
    public:
    const char  *what() const throw();
};

VECTOR  generateJacobsthal(unsigned long size);
 
template <typename T> void printContainer(T container)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

class PmergeMeVector
{
    public:
    PmergeMeVector();
    PmergeMeVector(const PmergeMeVector &src);
    PmergeMeVector    &operator=(const PmergeMeVector &rhs);
    ~PmergeMeVector();
    VECTOR          algo(VECTOR unsorted_vec);
    VECTOR          parseSequence(char **sequence);
    void            fill_and_convert(VECTOR &parsed_seq, std::string temp);
    VECTOR          insertSort(VECTOR small_nb, VECTOR large_nb);
    void            binarySearch(long index, VECTOR &small_nb, VECTOR &large_nb, unsigned long inserted_elems);
    VECTOR_PAIRS    makePairs(VECTOR parsed_seq);
    VECTOR_PAIRS    sortPairs(VECTOR sorted_large_nb, VECTOR_PAIRS pairs);
};

class PmergeMeDeque
{
    public:
    PmergeMeDeque();
    PmergeMeDeque(const PmergeMeDeque &src);
    PmergeMeDeque    &operator=(const PmergeMeDeque &rhs);
    ~PmergeMeDeque();
    DEQUE          algo(DEQUE unsorted_vec);
    DEQUE          parseSequence(char **sequence);
    void            fill_and_convert(DEQUE &parsed_seq, std::string temp);
    DEQUE          insertSort(DEQUE small_nb, DEQUE large_nb);
    void            binarySearch(long index, DEQUE &small_nb, DEQUE &large_nb, unsigned long inserted_elems);
    DEQUE_PAIRS   makePairs(DEQUE parsed_seq);
    DEQUE_PAIRS   sortPairs(DEQUE sorted_large_nb, DEQUE_PAIRS pairs);
};

#endif