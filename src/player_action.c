/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:16 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/24 15:13:12 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rotate_right(t_game *game)
{
	game->player.rotate_direction = 1;
	game->player.angl_rotation += game->player.rotate_direction * game->player.rotate_speed;
}

void rotate_left(t_game *game)
{
	game->player.rotate_direction = -1;
	game->player.angl_rotation += game->player.rotate_direction * game->player.rotate_speed;
}

void right_move(t_game *game)
{
	double move_speed;
	double move_steps;

	move_speed = 5;
	move_steps = move_speed;
	game->player.position_x += cos(game->player.angl_rotation + M_PI / 2) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation + M_PI / 2) * move_steps;
}

void left_move(t_game *game)
{
	double move_speed;
	double move_steps;

	move_speed = 5;
	move_steps = move_speed;
	game->player.position_x -= cos(game->player.angl_rotation + M_PI / 2) * move_steps;
	game->player.position_y -= sin(game->player.angl_rotation + M_PI / 2) * move_steps;
}

void down_move(t_game *game)
{
	double move_speed;
	double move_steps;

	move_speed = 5;
	game->player.move_direction = -1;
	move_steps = game->player.move_direction * move_speed;
	game->player.position_x += cos(game->player.angl_rotation) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation) * move_steps;
}

void up_move(t_game *game)
{
	double move_speed;
	double move_steps;

	move_speed = 5;
	game->player.move_direction = 1;
	move_steps = game->player.move_direction * move_speed;
	game->player.position_x += cos(game->player.angl_rotation) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation) * move_steps;
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
	else if (key.key == MLX_KEY_D && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		right_move(game);
	else if (key.key == MLX_KEY_A && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		left_move(game);
	else if (key.key == MLX_KEY_S && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		down_move(game);
	else if (key.key == MLX_KEY_W && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		up_move(game);
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	re_game(game);
}
