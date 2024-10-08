/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_deque.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:48:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/08 16:13:55 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeDeque::PmergeMeDeque() {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque &src)
{
    *this = src;
}

PmergeMeDeque  &PmergeMeDeque::operator=(const PmergeMeDeque &)
{
    return (*this);
}

PmergeMeDeque::~PmergeMeDeque() {}

DEQUE    PmergeMeDeque::algo(DEQUE unsorted_vec)
{
    DEQUE_PAIRS    vector_pairs;
    DEQUE          large_nb;
    DEQUE          small_nb;
    long            odd_case_nb = -1;
    
    if (unsorted_vec.size() % 2)
    {
        odd_case_nb = unsorted_vec.back();
        unsorted_vec.pop_back();
    }
    vector_pairs = this->makePairs(unsorted_vec);
    for (unsigned long i = 0; i < vector_pairs.size(); i++)
    {
        large_nb.push_back(vector_pairs[i].second);
    }
    if (large_nb.size() > 1)
        large_nb = this->algo(large_nb);
    vector_pairs = sortPairs(large_nb, vector_pairs);
    for (unsigned long i = 0; i < vector_pairs.size(); i++)
    {
        small_nb.push_back(vector_pairs[i].first);
    }
    if (odd_case_nb != -1)
        small_nb.push_back(odd_case_nb);
    return (insertSort(small_nb, large_nb));
}

DEQUE_PAIRS    PmergeMeDeque::makePairs(DEQUE parsed_seq)
{
    DEQUE_PAIRS    vector_pairs;
    
    for (unsigned long i = 0; i < parsed_seq.size(); i += 2)
    {
        if (parsed_seq[i] < parsed_seq[i + 1])
            vector_pairs.push_back(std::make_pair(parsed_seq[i], parsed_seq[i + 1]));
        else
            vector_pairs.push_back(std::make_pair(parsed_seq[i + 1], parsed_seq[i]));
    }
    return (vector_pairs);
}

DEQUE_PAIRS PmergeMeDeque::sortPairs(DEQUE sorted_large_nb, DEQUE_PAIRS pairs)
{
    DEQUE_PAIRS    sorted_pairs;
    
    for (unsigned long i = 0; i < sorted_large_nb.size(); i++)
    {
        for (unsigned long j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].second == sorted_large_nb[i])
            {
                sorted_pairs.push_back(pairs[j]);
                break ;
            }
        }
    }
    return (sorted_pairs);
}

DEQUE  PmergeMeDeque::insertSort(DEQUE small_nb, DEQUE large_nb)
{
    VECTOR                      jacobsthal_suit = generateJacobsthal(small_nb.size() + 10);
    std::vector<long>::iterator it_jacob;
    long                        last_index = -1;
    long                        index;
    unsigned long               inserted_elems = 0;
    
    
    it_jacob = jacobsthal_suit.begin();
    while (inserted_elems < small_nb.size())
    {
        index = std::min(*it_jacob, static_cast<long>(small_nb.size() - 1));
        while (index > last_index && index >= 0)
        {
            binarySearch(index, small_nb, large_nb, inserted_elems);
            inserted_elems++;
            index--;
        }
        last_index = *it_jacob;
        it_jacob++;
    }
    return (large_nb);
}

void    PmergeMeDeque::binarySearch(long index, DEQUE &small_nb, DEQUE &large_nb, unsigned long inserted_elems)
{
    std::deque<long>::iterator it_begin;
    std::deque<long>::iterator it_mid;
    std::deque<long>::iterator it_end;

    it_begin = large_nb.begin();
    it_end = large_nb.begin() + index + inserted_elems;
    while (it_begin < it_end && large_nb.size() > 1 && it_end != it_begin + 1)
    {
        it_mid = it_begin + (std::distance(it_begin, it_end) / 2);
        if (small_nb[index] < *it_mid)
            it_end = it_mid;
        else
            it_begin = it_mid;
    }
    if (small_nb[index] < *it_begin)
        large_nb.insert(it_begin, small_nb[index]);
    else
        large_nb.insert(it_end, small_nb[index]);
}

DEQUE    PmergeMeDeque::parseSequence(char **sequence)
{
    std::string str_seq;
    std::string temp;
    DEQUE      unsorted_vect;
    
    for (int index_seq = 0; sequence[index_seq]; index_seq++)
    {
        str_seq = str_seq + " " + std::string(sequence[index_seq]);
    }
    for (unsigned long i = 0; i < str_seq.size(); i++)
    {
        if (str_seq[i] == ' ')
        {
            if (!temp.empty())
            {
                this->fill_and_convert(unsorted_vect, temp);
                temp.clear();
            }
        }
        else
            temp += str_seq[i];
    }
    if (!temp.empty())
        this->fill_and_convert(unsorted_vect, temp);
    return (unsorted_vect);
}

void    PmergeMeDeque::fill_and_convert(DEQUE &parsed_seq, std::string temp)
{
    char    *end;
    errno = 0;

    if (strtol(temp.c_str(), &end, 10) < 0 || errno == ERANGE || *end != '\0')
        throw ARG_ERROR();
    else if (std::find(parsed_seq.begin(), parsed_seq.end(), strtol(temp.c_str(), &end, 10)) == parsed_seq.end())
        parsed_seq.push_back(strtol(temp.c_str(), &end, 10));
}