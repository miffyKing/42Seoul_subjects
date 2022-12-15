/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:44:01 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/15 18:46:37 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(int c)
{
    if (write(1, &c, 1) == -1)
    {
        return (-1);
    }
    return (1);
}

int ft_print_string(const char *str)
{
    int len;

    if (str == NULL)
    {
        if (write(1, "(null)", 6) == -1)
            return -1;
        return (6);
    }
    len = ft_strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (write(1, str+i, 1) == -1)
            return -1;
    }
    return len;


}