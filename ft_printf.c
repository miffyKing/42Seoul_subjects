/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:22:43 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/15 19:09:17 by chobyounghw      ###   ########.fr       */
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
    // else if (c == 'p'){}
    // else if (c == 'd'){}
    // else if (c == 'i'){}
    // else if (c == 'u') {}
    // else if (c == 'x') {}
    // else if (c == 'X') {}
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

int main()
{
    ft_printf("qwerty  %c  %%  %c ewerw\n", 'a', 'W');
    ft_printf("sqwe %s |", "sexsex");
    return 0;
}