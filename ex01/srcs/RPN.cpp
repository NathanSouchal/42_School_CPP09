/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:08:29 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/01 10:48:07 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN &RPN::operator=(const RPN &rhs)
{
    (void)rhs;
    return (*this);
}

RPN::~RPN() {}

const char  *RPN::ARG_ERROR::what() const throw()
{
    return ("Error");
}

void RPN::read_arg(char *arg_str)
{
    for (int i = 0; arg_str[i]; i++)
    {
        if (i % 2 == 0 && isdigit(arg_str[i]))
            this->push(arg_str[i] - '0');
        else if (i % 2 == 0 && is_operator(arg_str[i]))
            this->calculate(arg_str[i]);
        else if (arg_str[i] !=  ' ')
            throw RPN::ARG_ERROR();
    }
}

bool    RPN::is_operator(char to_test)
{
    if (to_test == '-' || to_test == '+' || to_test == '*' || to_test == '/')
        return (true);
    return (false);
}

void    RPN::calculate(char operator_)
{
    int a;
    int b;
    
    if (this->empty())
        throw RPN::ARG_ERROR();
    b = this->top();
    this->pop();
    if (this->empty())
        throw RPN::ARG_ERROR();
    a = this->top();
    this->pop();
    if (operator_ == '-')
        this->push(a - b);
    else if (operator_ == '+')
        this->push(a + b);
    else if (operator_ == '*')
        this->push(a * b);
    else if (operator_ == '/')
    {
        if (b == 0)
        {
            std::cout << "Division by zero" << std::endl;
            throw RPN::ARG_ERROR();
        }
        this->push(a / b);
    }
}