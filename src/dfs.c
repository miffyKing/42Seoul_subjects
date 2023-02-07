/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:20:38 by bcho              #+#    #+#             */
/*   Updated: 2023/01/21 15:09:03 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate(char **map, int col, int row)
{
	char	**tmp;
	int		i;

	col = 0;
	tmp = (char **)malloc(sizeof(char *) * (row)+1);
	i = 0;
	while (i < row)
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	freetmp(char **map, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_func(int j, int i, t_game *game, char **tmpmap)
{
	t_map	map;

	map = game->map;
	if (dfs2(j, i, game->player.pos, tmpmap) == 0)
	{
		freetmp(tmpmap, map.size.row);
		error_exit("Map is not valid.\n");
	}
	freetmp(tmpmap, map.size.row);
}

void	check_validroute(t_game *game)
{
	t_map	map;
	char	**tmpmap;
	int		i;
	int		j;

	map = game->map;
	i = 0;
	while (i <= map.size.col)
	{
		j = 0;
		while (j < map.size.row)
		{
			if (map.chunks[j][i] == 'C' || map.chunks[j][i] == 'E')
			{
				tmpmap = duplicate(map.chunks, map.size.col, map.size.row);
				free_func(j, i, game, tmpmap);
			}
			j++;
		}
		i++;
	}
}

int	dfs2(int item_row, int item_col, t_pos pos, char **map)
{
	int		count;

	if (map[item_row][item_col] == '1')
	{
		return (0);
	}
	if (map[item_row][item_col] != 'V')
	{
		if (map[item_row][item_col] == 'P')
		{
			return (1);
		}
		map[item_row][item_col] = 'V';
		count = 0;
		count += dfs2(item_row + 1, item_col, pos, map);
		count += dfs2(item_row, item_col + 1, pos, map);
		count += dfs2(item_row - 1, item_col, pos, map);
		count += dfs2(item_row, item_col - 1, pos, map);
		return (count);
	}
	return (0);
}
