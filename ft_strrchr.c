/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:41:27 by bcho              #+#    #+#             */
/*   Updated: 2022/07/11 17:24:46 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	if (s[0] == 0 && (char)c == 0)
		return ((char *)&s[0]);
	else if (s[0] == 0)
		return (NULL);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			tmp = (char *)s + i;
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	return (tmp);
}
