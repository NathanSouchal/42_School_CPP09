/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:54 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/01 10:59:59 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char **argv)
{
    RPN rpn;
    
    if (argc != 2)
    {
        std::cout << "Enter ONE argument please" << std::endl;
        return (1);
    }
    try
    {
        rpn.read_arg(argv[1]);
        if (rpn.size() == 1)
            std::cout << rpn.top() << std::endl;
        else
            throw RPN::ARG_ERROR();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}