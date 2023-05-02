/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:26:28 by bcho              #+#    #+#             */
/*   Updated: 2022/07/12 16:19:57 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*src;
	char		*arr;
	size_t		src_len;
	size_t		dst_len;

	if (!s)
		return (0);
	src_len = ft_strlen(s);
	if (start > src_len)
		start = src_len;
	src = s + start;
	dst_len = ft_strlen(src);
	if (dst_len > len)
		dst_len = len;
	arr = ft_calloc(dst_len + 1, sizeof(char));
	if (!arr)
		return (0);
	ft_memcpy(arr, src, dst_len);
	arr[dst_len] = '\0';
	return (arr);
}
