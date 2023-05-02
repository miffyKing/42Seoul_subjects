/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:53:17 by bcho              #+#    #+#             */
/*   Updated: 2023/01/17 13:53:20 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_game *game, char *img_path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(game->mlx, img_path, &width, &height);
	if (!img)
		error_exit("failed convertion xpm to img.");
	return (img);
}

void	ft_put_img(t_game *game, void *img, t_pos img_pos)
{
	int	x;
	int	y;

	x = img_pos.col;
	y = img_pos.row;
	mlx_put_image_to_window(game->mlx, game->win, img, x * PX, y * PX);
}
