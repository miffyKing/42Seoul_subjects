/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:20:35 by bcho              #+#    #+#             */
/*   Updated: 2023/01/21 13:55:47 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr2(char *s, int c)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	while (s[size])
		size++;
	if (c == 0)
		return ((char *)&s[size]);
	return (0);
}

char	*ft_strjoin2(char *backup, char *tmp)
{
	char	*arr;
	int		i;
	int		tmp_i;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = 0;
	}
	if (!tmp)
		return (0);
	arr = (char *)malloc((ft_strlen2(backup) + ft_strlen2(tmp)) + 1);
	if (!arr)
		return (0);
	i = -1;
	while (backup[++i] && backup)
		arr[i] = backup[i];
	tmp_i = i;
	i = 0;
	while (tmp[i])
		arr[tmp_i++] = tmp[i++];
	arr[tmp_i] = 0;
	free(backup);
	return (arr);
}
