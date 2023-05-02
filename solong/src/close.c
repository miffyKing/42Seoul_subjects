/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:32 by bcho              #+#    #+#             */
/*   Updated: 2023/01/20 14:25:38 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *msg)
{
	printf("ERROR: %s\n", msg);
	exit(1);
}

int	close_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("game end!");
	exit(0);
}
