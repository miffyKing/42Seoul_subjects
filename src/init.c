/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:09:56 by bcho              #+#    #+#             */
/*   Updated: 2023/01/20 14:29:41 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, const char *map_path)
{
	init_map(game, map_path);
	init_player(game);
	check_validroute(game);
	init_mlx_win(game);
	init_img(game);
}

void	init_map(t_game *game, const char *map_path)
{
	check_map_path(map_path, ".ber");
	get_map_chunks(game, map_path);
	get_map_size(&game->map);
	check_rectangle(&game->map);
	check_surround(&game->map);
	check_components(&game->map);
}

void	init_img(t_game *game)
{
	game->imgs.snow = get_img(game, "./asset/snow.xpm");
	game->imgs.wall = get_img(game, "./asset/bhface2.xpm");
	game->imgs.sign = get_img(game, "./asset/ejaeeFace.xpm");
	game->imgs.home = get_img(game, "./asset/ybackFace2.xpm");
	game->imgs.dayun = get_img(game, "./asset/dayunFace.xpm");
}

void	init_mlx_win(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("failed init mlx");
	game->win = mlx_new_window(game->mlx, game->map.size.col * PX,
			game->map.size.row * PX, "so_long");
	if (!game->win)
		error_exit("failed init win");
}

void	init_player(t_game *game)
{	
	game->player.move_cnt = 0;
	game->player.item_cnt = 0;
	get_player_pos(game);
}
