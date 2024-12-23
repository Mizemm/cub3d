/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:16 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/23 19:18:49 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rotate_right(t_game *game)
{
	double rotation_speed;
	
	rotation_speed = 5 * (M_PI / 180);
	game->player.direction = 1;
	game->player.angl_rotation += game->player.direction * rotation_speed;
}

void rotate_left(t_game *game)
{
	double rotation_speed;
	
	rotation_speed = 5 * (M_PI / 180);
	game->player.direction = -1;
	game->player.angl_rotation += game->player.direction * rotation_speed;
}

void right_move(t_game *game)
{
	(void)game;
}

void left_move(t_game *game)
{
	(void)game;
}

void key_hook(mlx_key_data_t key, void *param)
{
	t_game *game;
	
	game = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (key.key == MLX_KEY_RIGHT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		rotate_right(game);
	else if (key.key == MLX_KEY_LEFT && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		rotate_left(game);
	else if (key.key == MLX_KEY_A && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		right_move(game);
	game->player.direction = 0;
	re_game(game);
}
