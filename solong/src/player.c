/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:10:25 by bcho              #+#    #+#             */
/*   Updated: 2023/01/17 13:18:05 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.size.row)
	{
		col = 0;
		while (col < game->map.size.col)
		{
			if (game->map.chunks[row][col] == 'P')
			{
				game->player.pos.row = row;
				game->player.pos.col = col;
				return ;
			}
			++col;
		}
		++row;
	}
}
