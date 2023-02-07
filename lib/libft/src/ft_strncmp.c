/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:08:28 by bcho              #+#    #+#             */
/*   Updated: 2022/07/08 20:53:16 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	s1_leng;
	unsigned int	s2_leng;
	unsigned int	i;

	s1_leng = ft_strlen(s1);
	s2_leng = ft_strlen(s2);
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n && (s1[i] || s2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
