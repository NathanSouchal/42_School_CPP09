/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:54 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/02 10:22:23 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char **argv)
{
    RPN rpn;
    
    if (argc != 2)
    {
        std::cerr << "Enter ONE argument please" << std::endl;
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
        std::cerr << e.what() << std::endl;
    }
    return (0);
}