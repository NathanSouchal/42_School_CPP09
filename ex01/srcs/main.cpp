/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:42:54 by nsouchal          #+#    #+#             */
/*   Updated: 2024/10/01 09:46:49 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int main(int argc, char **argv)
{
    RPN rpn;
    
    (void)argc;
    rpn.read_arg(argv[1]);
    std::cout << rpn.top() << std::endl;
    return (0);
}