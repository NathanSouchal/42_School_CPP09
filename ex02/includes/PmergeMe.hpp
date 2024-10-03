/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:32 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/03 14:44:06 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <cstring>
# include <cstdlib>
# include <cerrno>
# include <climits>

typedef std::vector<std::pair<long, long> > VECTOR_PAIRS;
typedef std::vector<long> VECTOR;

class ARG_ERROR : public std::exception
{
    public:
    const char  *what() const throw();
};

VECTOR  generateJacobsthal(unsigned long size);
 
class PmergeMeVector
{
    
    private:
    long    odd_case_nb;
    
    
    public:
    PmergeMeVector();
    PmergeMeVector(const PmergeMeVector &src);
    PmergeMeVector    &operator=(const PmergeMeVector &rhs);
    ~PmergeMeVector();
    VECTOR          algo(VECTOR unsorted_vec);
    VECTOR          parseSequence(char **sequence);
    void            fill_and_convert(VECTOR &parsed_seq, std::string temp);
    VECTOR          insertSort(VECTOR small_nb, VECTOR large_nb);
    VECTOR_PAIRS    makePairs(VECTOR parsed_seq);
    VECTOR_PAIRS    sortPairs(VECTOR sorted_large_nb, VECTOR_PAIRS pairs);
};

#endif