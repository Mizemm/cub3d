/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:16 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/22 20:43:25 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void r_right(t_game *game)
{
	double x_ep;
	double y_ep;
	int dx;
	int dy;
	int steps;
	double rotation_speed;
	
	rotation_speed = 1;
	game->player.direction = 1;
	x_ep = game->player.position_x + (30 * cos(game->player.angl_rotation));
	y_ep = game->player.position_y + (30 * sin(game->player.angl_rotation));
	dx = x_ep - game->player.position_x;
	dy = y_ep - game->player.position_y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	game->player.angl_rotation += game->player.direction * rotation_speed;
	game->player.position_x = cos(game->player.angl_rotation) * steps;
	game->player.position_y = sin(game->player.angl_rotation) * steps;
}

void r_left(t_game *game)
{
	(void)game;
}

void key_hook(mlx_key_data_t key, void *param)
{
	t_game *game;
	
	game = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (key.key == MLX_KEY_RIGHT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		r_right(game);
	if (key.key == MLX_KEY_LEFT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		r_left(game);
	game->player.direction = 0;
	re_game(game);
}
