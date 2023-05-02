/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:09:48 by bcho              #+#    #+#             */
/*   Updated: 2022/07/11 17:46:58 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
