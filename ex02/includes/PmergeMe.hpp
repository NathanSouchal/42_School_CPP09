/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:45:32 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/01 16:23:47 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <utility>
# include <cstring>

class PmergeMeVector
{
    
    private:
    std::vector<std::pair<int, int> > vector_pairs;
    
    
    public:
    PmergeMeVector();
    PmergeMeVector(const PmergeMeVector &src);
    PmergeMeVector    &operator=(const PmergeMeVector &rhs);
    ~PmergeMeVector();
    void    parseSequence(char **sequence);
    class ARG_ERROR : public std::exception
    {
        public:
        const char  *what() const throw();
    };
};

#endif