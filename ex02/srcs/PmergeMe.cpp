/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:48:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/02 09:31:18 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector() {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &src)
{
    *this = src;
}

PmergeMeVector  &PmergeMeVector::operator=(const PmergeMeVector &rhs)
{
    if (this != &rhs)
    {
        this->vector_pairs = rhs.vector_pairs;
    }
    return (*this);
}

PmergeMeVector::~PmergeMeVector() {}

const char *PmergeMeVector::ARG_ERROR::what() const throw()
{
    return ("Error");    
}

void    PmergeMeVector::parseSequence(char **sequence)
{
    long                        a;
    long                        b;
    char                        *end;
    std::string                 str_seq;
    std::string                 temp;
    std::vector<std::string>    splited_seq;
    
    for (int index_seq = 0; sequence[index_seq]; index_seq++)
    {
        str_seq = str_seq + " " + std::string(sequence[index_seq]);
    }
    for (int i = 0; i < str_seq.size(); i++)
    {
        if (str_seq[i] == ' ')
        {
            if (!temp.empty())
            {
                splited_seq.push_back(temp);
                temp.clear();
            }
        }
        else
            temp += str_seq[i];
    }
    if (!temp.empty())
        splited_seq.push_back(temp);
    for (int i = 0; i < splited_seq.size() ; i++)
    {
        std::cout << splited_seq[i] << std::endl;
    }
}