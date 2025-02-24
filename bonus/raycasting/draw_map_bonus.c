/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:41:32 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 02:14:36 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_floor(t_game *game)
{
	while (HEIGHT > game->y_draw)
	{
		game->x_draw = 0;
		while (WIDTH > game->x_draw)
		{
			mlx_put_pixel(game->image, game->x_draw, game->y_draw,
				rgbt_color(game->floor_color_int[0], game->floor_color_int[1],
					game->floor_color_int[2], 255));
			game->x_draw++;
		}
		game->y_draw++;
	}
}

void	draw_ceiling(t_game *game)
{
	game->x_draw = 0;
	game->y_draw = 0;
	while (HEIGHT / 2 > game->y_draw)
	{
		game->x_draw = 0;
		while (WIDTH > game->x_draw)
		{
			mlx_put_pixel(game->image, game->x_draw, game->y_draw,
				rgbt_color(game->ceiling_color_int[0],
					game->ceiling_color_int[1], game->ceiling_color_int[2],
					255));
			game->x_draw++;
		}
		game->y_draw++;
	}
}
