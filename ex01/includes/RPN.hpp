/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:00:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/01 09:42:15 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstring>
# include <stack>

class RPN : public std::stack<int>
{
  public:
  RPN();
  RPN(const RPN &src);
  RPN   &operator=(const RPN &rhs);
  ~RPN();
  void  read_arg(char *arg_str);
  bool  is_operator(char to_test);
  void  calculate(char operator_);
  class ARG_ERROR : public std::exception
  {
    public:
    const char  *what() const throw();    
  };
    
};

#endif 