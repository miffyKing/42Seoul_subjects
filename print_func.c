/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:44:01 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/16 00:31:05 by chobyounghw      ###   ########.fr       */
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

int ft_print_numeric(long long numeric, const char type)
{
    char * base;
    int base_size;

    if (numeric == 0)
    {
        if(write(1, "0", 1) == -1)
            return -1;
        return 1;
    }
    base = ft_setbase(type);
    base_size = ft_strlen(base);
    
    if (num_to_base(numeric, base, base_size) == -1)
        return (-1);
    
    
    return (1);
}

char * ft_setbase(const char type)      
{
    if (type == 'd' || type == 'i' || type == 'u')
        return ("0123456789");
    else if (type == 'x' || type == 'p')
        return ("0123456789abcdef");
    else if (type == 'X')
        return ("0123456789ABCDEF");
    return (0);   
}

int num_to_base(long long numeric, char * base, int base_size) //ft_putnbr_base
{
    char table[12];
    int idx;
    int res;

    idx = 0;
    if (numeric < 0)
    {
        if (write(1, "-", 1) == -1)
            return (-1);
        numeric *= -1;
    }
    idx = 0;
    while(numeric)
    {
        table[idx] = base[numeric % base_size];
        numeric /= base_size;
        idx++;
    }
    res = idx--;
    while (idx >= 0)
    {
        if (write(1, &table[idx], 1) == -1)
        {
            return (-1);
        }
        idx--;
    }
    return res;
}