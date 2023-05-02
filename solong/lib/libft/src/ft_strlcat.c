/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:26:59 by bcho              #+#    #+#             */
/*   Updated: 2022/07/12 15:15:34 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_leng;
	unsigned int	j;
	unsigned int	i;
	size_t			src_leng;

	j = 0;
	i = 0;
	dest_leng = ft_strlen(dest);
	src_leng = ft_strlen(src);
	if (dest_leng < size)
	{
		i = dest_leng;
		while (i < size - 1 && src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}	
		dest[i] = '\0';
	}
	else
		return (src_leng + size);
	return (dest_leng + src_leng);
}
