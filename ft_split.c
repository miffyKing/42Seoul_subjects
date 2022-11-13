/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:19:57 by bcho              #+#    #+#             */
/*   Updated: 2022/07/12 16:19:24 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char target, char c)
{
	if (target == c)
		return (0);
	return (1);
}

static int	word_count(char const *str, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], c) == 0)
			i++;
		if (str[i])
			result++;
		while (str[i] && check_sep(str[i], c) == 1)
			i++;
	}
	return (result);
}

static int	count_length(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_sep(str[i], c) == 0)
			break ;
		i++;
	}
	return (i);
}

static char	*put_words(char const *str, char c)
{
	int		word_len;
	char	*words;
	int		i;

	word_len = count_length(str, c);
	words = (char *)malloc(sizeof(char) * (word_len + 1));
	i = 0;
	while (i < word_len)
	{
		words[i] = str[i];
		i++;
	}
	words[i] = '\0';
	return (words);
}

char	**ft_split(char const *str, char c)
{
	int		word_cnt;
	char	**split;
	int		i;
	int		j;

	if (!str)
		return (0);
	word_cnt = word_count(str, c);
	j = 0;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!split)
		return (0);
	while (str[i])
	{
		while (str[i] && check_sep(str[i], c) == 0)
			str++;
		if (str[i])
			split[j++] = put_words(str, c);
		while (str[i] && check_sep(str[i], c) == 1)
			str++;
	}
	split[j] = 0;
	return (split);
}

// int main(void)
// {
// 	char ** result;
// 	result = ft_split("qwe sddfsdfqw ed a weq d", ' ');
// //	int i = 0;
// 	// while (result[i])
// 	// {
// 	// 	printf("%s\n", result[i]);
// 	// 	i++;
// 	// }
// 	return 0;
// }