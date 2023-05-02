/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:09:43 by bcho              #+#    #+#             */
/*   Updated: 2022/07/12 16:19:51 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*tmp;

	if (!s1 || !set)
		return (0);
	back = ft_strlen(s1);
	front = 0;
	while (s1[front] && ft_strchr(set, s1[front]))
	{
		front++;
	}
	while (s1[back - 1] && ft_strchr(set, s1[back - 1]) && back > front)
	{
		back--;
	}
	tmp = (char *)malloc(sizeof(char) * (back - front + 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1 + front, back - front + 1);
	return (tmp);
}
