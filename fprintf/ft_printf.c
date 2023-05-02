/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:43 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/17 00:35:13 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_format_specifier(const char c, va_list *ap)
{
    if (c == 'c')
    {
        return ft_print_char(va_arg(*ap, int));
    }
    else if (c == 's')
    {
        return ft_print_string(va_arg(*ap, const char *));
    }
    else if (c == 'p')
    {
        return ft_print_ptr(va_arg(*ap, unsigned long long ));
    }
    else if (c == 'd')
    {
        return ft_print_numeric(va_arg(*ap, int), 'd');
    }
    else if (c == 'i')
    {
        return ft_print_numeric(va_arg(*ap, int), 'i');
    }
    else if (c == 'u') 
    {
        return ft_print_numeric(va_arg(*ap, unsigned int), 'u');
    }
    
    else if (c == 'x') 
    {
        return ft_print_numeric(va_arg(*ap, unsigned int), 'x');   //이거 사이즈 long long 이유?
    }
    else if (c == 'X') 
    {
        return ft_print_numeric(va_arg(*ap, unsigned int), 'X');   //이거 사이즈 long long 이유?
    }
    else if (c == '%') 
    {
        return ft_print_char('%');
    }
    else
        return -1;  
}

int ft_printf(const char *format, ...) //왜 const?
{
    va_list ap;
    int     printed_len;
    int valid_format;
    
    printed_len = 0;
    va_start(ap, format);
    
    while (*format)
    {
        if(*format == '%')
        {
            valid_format = check_format_specifier(*++format, &ap);
            if (valid_format == -1)
                return (-1);
            printed_len += valid_format;
        }
        
        else
        {
            valid_format = ft_print_char((int)*format);
            if (valid_format == -1)
                return -1;
            printed_len++;
        }
        format++;

    }
    return (printed_len);
}

#include <stdio.h>

int main()
{
    ft_printf("qwerty  %c  %%  %c ewerw\n", 'a', 'W'); // %c , %%
    printf("qwerty  %c  %%  %c ewerw\n", 'a', 'W');
    
    ft_printf("sqwe %s |\n", "hi nice to see u");         // %s
    printf("sqwe %s |\n", "hi nice to see u");

    ft_printf("qwe %d sdfsd %d \n", 12, __INT_MAX__);                     // "%d"
    printf("qwe %d sdfsd %d \n", 12, __INT_MAX__);

    int *p;

    ft_printf("%x %X %p dddddddd\n", 162, 162, p);         //%x %X %p
    printf("%x %X %p dddddddd\n", 162, 162, p);       

    ft_printf("%u sdsdsd\n", __INT_MAX__);
    printf("%u sdsdsd\n", __INT_MAX__);

    ft_printf("%u sdsdsd\n", 12);
    printf("%u sdsdsd\n", 12);
    
    return 0;
}