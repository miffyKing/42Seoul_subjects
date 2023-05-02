/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:44:01 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/17 00:23:24 by chobyounghw      ###   ########.fr       */
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
    int digit_length;

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
    digit_length = 0;
    if (type == 'd' || type == 'i' || type == 'u')
    {
        digit_length = get_length_by_digit(numeric, 10);
    }
    else        // u,x,X
        digit_length = get_length_by_digit(numeric, 16);
    return (digit_length);
}

char * ft_setbase(const char type)      
{
    if (type == 'd' || type == 'i' || type == 'u')
        return ("0123456789");
    else if (type == 'x' || type == 'p')
        return ("0123456789abcdef");
    else if (type == 'X')
        return ("0123=456789ABCDEF");
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

int get_length_by_digit(long long num, int type)
{
    int	cnt;

	cnt = 1;
	if (num < 0)
	{
		cnt++;
		num *= -1;
	}
	while (1)
	{
		if (num < type)
			break ;
		num /= type;
		cnt++;
	}
	return (cnt);
}

int ft_print_ptr(unsigned long long ptr)
{
char	*hex;
	char	stack[17];
	int		idx;
	int		res;

	hex = ft_setbase('X');
	idx = 0;
	if (write (1, "0x", 2) == -1)
		return (-1);
	if (ptr == 0)
	{
		if (write (1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	while (ptr)
	{
		stack[idx] = hex[ptr % 16];
		ptr /= 16;
        idx++;
	}
	res = idx--;
	while (idx >= 0)
    {
		if (write (1, &stack[idx], 1) == -1)
		{
            return (-1);
        }
        idx--;
    }           //여기 메서드로 빼기.
	return (res + 2);
}
