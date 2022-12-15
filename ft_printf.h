/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:23:06 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/15 18:46:52 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int check_format_specifier(const char c, va_list *ap);
int ft_printf(const char *format, ...);


int ft_print_char(int c);
int ft_print_string(const char * str);

size_t ft_strlen(const char *s);

#endif
