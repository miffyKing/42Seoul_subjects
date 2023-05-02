/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:07:39 by bcho              #+#    #+#             */
/*   Updated: 2022/07/12 16:20:30 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t	i;

	if (!dest && !source)
		return (0);
	i = 0;
	while (i < num)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(source + i);
		i++;
	}
	return (dest);
}
