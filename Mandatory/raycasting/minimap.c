/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:58:06 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/22 23:34:56 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_minimap(t_game *game)
{
	game->minimap_width = WIDTH * MINIMAP_SCALE;
	game->minimap_height = HEIGHT * MINIMAP_SCALE;
	int i;
	int j;
	
	i = -50;
	j = 0;
	game->minimap_img = mlx_new_image(game->mlx, game->minimap_width, game->minimap_height);
	if ((!game->minimap_img) || (mlx_image_to_window(game->mlx, game->minimap_img, 10, 10)) < 0)
		return ;
	while (i < 50)
	{
		j = -50;
		while (j < 100)
		{
			int x = (game->player.position_x * MINIMAP_SCALE) + j;
			int y = (game->player.position_y * MINIMAP_SCALE) + i;
			if (x >= 0 && y >= 0 && x < game->minimap_width && y < game->minimap_height)
				mlx_put_pixel(game->minimap_img, x, y, 0xffffffff);
			j++;
		}
		i++;
	}
	// int px = (game->player.position_x * MINIMAP_SCALE);
	// int py = (game->player.position_y * MINIMAP_SCALE);
	// int x1 = -5;
	// int y1 = -5;
	// for (int d = 0; d < 5; d++)
	// {
	// 	for (int e = 0; e < 5; e++)
	// 	{
	// 		mlx_put_pixel(game->minimap_img, px + e, py + d, 0xFF0000);
	// 	}
	// }
}
