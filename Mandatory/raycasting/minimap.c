/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:58:06 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/23 21:16:16 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void minimap_line(t_game *game, double px, double py)
{
	int i;
	double dx;
	double dy;
	double steps;
	double x_inc;
	double y_inc;
	double x1;
	double y1;

	i = -1;
	x1 = px + 15 * cos(game->player.angle_rotation);
	y1 = py + 15 * sin(game->player.angle_rotation);
	dx = x1 - px;
	dy = y1 - py;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (++i <= steps)
	{
		mlx_put_pixel(game->minimap_img, round(px), round(py), 0xFF0000);
		if (px < 0 || py < 0 || px >= game->minimap_width || py >= game->minimap_width)
            break;
		px += x_inc;
		py += y_inc;
	}
}

void minimap_player(t_game *game)
{
	double px;
	double py;
	int x1;
	int y1;
	int i;
	int j;

	px = game->minimap_width / 2;
	py = game->minimap_height / 2;

	i = -3;
	j = -3;
	while (i < 3)
	{
		j = -3;
		while (j < 3)
		{
			mlx_put_pixel(game->minimap_img, px + j, py + i, 0xFF0000);
			j++;
		}
		i++;
	}
	minimap_line(game, px, py);
}

void minimap_grid(t_game *game)
{
	size_t x;
	size_t y;
	
	for (y = 0; y < game->minimap_height; y += UNIT_SIZE)
	{
		for (x = 0; x < game->minimap_width; x++)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0xb5b8b7);
		}
	}
	for (x = 0; x < game->minimap_width; x += UNIT_SIZE)
	{
		for (y = 0; y < game->minimap_height; y++)
		{
			mlx_put_pixel(game->minimap_img, x, y, 0xb5b8b7);
		}
	}
}

void draw_minimap(t_game *game)
{
	game->minimap_width = 150;
	game->minimap_height = 90;
	int i;
	int j;
	
	i = 0;
	j = 0;
	game->minimap_img = mlx_new_image(game->mlx, game->minimap_width, game->minimap_height);
	if ((!game->minimap_img) || (mlx_image_to_window(game->mlx, game->minimap_img, 10, 10)) < 0)
		return ;
	while (i < game->minimap_height)
	{
		j = 0;
		while (j < game->minimap_width)
		{
				mlx_put_pixel(game->minimap_img, j, i, 0xffffffff);
			j++;
		}
		i++;
	}
	minimap_grid(game);
	minimap_player(game);
}
