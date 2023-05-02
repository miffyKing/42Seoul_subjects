/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:30:51 by bcho              #+#    #+#             */
/*   Updated: 2022/07/08 21:26:15 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	if (size > 0)
	{
		while (src[idx] && idx < (size - 1))
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = 0;
	}
	while (src[cnt])
		cnt++;
	return (cnt);
}
