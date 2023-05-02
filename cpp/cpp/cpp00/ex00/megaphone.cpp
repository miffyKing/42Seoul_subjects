/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:32:44 by bcho              #+#    #+#             */
/*   Updated: 2023/04/24 16:46:25 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char** av)
{
    if (ac >= 2) {
    {
        for (int idx = 1; idx < ac; idx++)
        {
            int len = strlen(av[idx]);
            for (int i = 0; i < len; i++) 
            {
                std::cout<<static_cast<char>(std::toupper(av[idx][i]));            }
            }
        }
    }
    else {
        std::cout<<"*  LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    return 0;   
} 
