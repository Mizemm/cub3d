/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:41:32 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/14 18:40:31 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void draw_line(t_game *game, t_ray ray)
{
	int i;
	double dx;
	double dy;
	double x_tmp;
	double y_tmp;
	double steps;
	double x_inc;
	double y_inc;

	i = -1;
	dx = ray.wallHitX - game->player.position_x;
	dy = ray.wallHitY - game->player.position_y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x_tmp = game->player.position_x;
	y_tmp = game->player.position_y;
	while (++i <= steps)
	{
		if (x_tmp < 0 || y_tmp < 0 || x_tmp >= game->WIDTH * UNIT_SIZE || y_tmp >= game->HEIGHT * UNIT_SIZE)
            break;
		mlx_put_pixel(game->image, round(x_tmp), round(y_tmp), 0xFF0000ff);
		x_tmp += x_inc;
		y_tmp += y_inc;
	}
}

void draw_background(t_game *game)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	game->image = mlx_new_image(game->mlx, game->WIDTH * UNIT_SIZE, game->HEIGHT * UNIT_SIZE);
	if ((!game->image) || (mlx_image_to_window(game->mlx, game->image, 0, 0) < 0))
		return ;
	while (game->HEIGHT * UNIT_SIZE > y)
	{
		x = 0;
		while (game->WIDTH * UNIT_SIZE > x)
		{
			mlx_put_pixel(game->image, x, y, 0xFFFFFFFF);
			x++;	
		}
		y++;
	}
}

void draw_wall(t_game *game)
{
	int x;
	int y;
	int i;
	int j;
	int position_x;
	int position_y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	position_x = 0;
	position_y = 0;
	while (game->map[i])
	{
		j = 0;
		position_x = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				y = 0;
				while (UNIT_SIZE > y)
				{
					x = 0;
					while (UNIT_SIZE > x)
					{
						mlx_put_pixel(game->image, x + position_x, y + position_y, 0x000000FF);
						x++;
					}
					y++;
				}
			}
			j++;
			position_x += UNIT_SIZE;	
		}
		i++;
		position_y += UNIT_SIZE;
	}
}

void draw_player(t_game *game)
{
	int x;
	int y;
	
	x = -5;
	y = -5;
	while (y < 5)
	{
		x = -5;
		while (x < 5)
		{
			mlx_put_pixel(game->image, game->player.position_x + x, game->player.position_y + y, 0xFF0000ff);
			x++;
		}
		y++;
	}
}
