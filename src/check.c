/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:30:13 by bcho              #+#    #+#             */
/*   Updated: 2023/01/18 19:47:26 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_path(const char *map_path, const char *suffix)
{	
	int		p_len;
	int		s_len;

	p_len = ft_strlen(map_path);
	s_len = ft_strlen(suffix);
	if (p_len < 4)
		error_exit("invalid file suffix.");
	if (ft_strncmp(suffix, &map_path[p_len - s_len], s_len))
		error_exit("invalid file suffix.");
}

void	check_rectangle(t_map *map)
{
	int	row;
	int	diff;

	row = 0;
	while (row < map->size.row)
	{
		diff = ft_strlen(map->chunks[row]);
		if (map->size.col != diff)
			error_exit("map is not rectangle.");
		++row;
	}
}

void	check_surround(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.col)
	{
		if (map->chunks[0][i] != '1')
			error_exit("map is not surrounded top wall.");
		if (map->chunks[map->size.row - 1][i] != '1')
			error_exit("map is not surrounded bottom wall.");
		++i;
	}
	i = 0;
	while (i < map->size.row)
	{
		if (map->chunks[i][0] != '1')
			error_exit("map is not surrounded left wall.");
		if (map->chunks[i][map->size.col - 1] != '1')
			error_exit("map is not surrounded right wall.");
		++i;
	}
}

void	check_components(t_map *map)
{
	const char	*components = "10CEP";
	int			row;
	int			col;

	ft_bzero(&map->flags, sizeof(map->flags));
	row = 0;
	while (row < map->size.row)
	{
		col = 0;
		while (col < map->size.col)
		{
			if (!ft_strchr(components, map->chunks[row][col]))
				error_exit("invlalid component.");
			if (map->chunks[row][col] == 'C')
				map->flags.sign++;
			else if (map->chunks[row][col] == 'E')
				map->flags.home++;
			else if (map->chunks[row][col] == 'P')
				map->flags.dayun++;
			++col;
		}
		++row;
	}
	if (map->flags.sign < 1 || map->flags.home < 1 || map->flags.dayun != 1)
		error_exit("invlalid component count.");
}
