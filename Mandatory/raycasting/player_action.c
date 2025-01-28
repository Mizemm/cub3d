/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:16 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/29 00:24:25 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rotate_right(t_game *game)
{
	game->player.rotate_direction = 1;
	game->player.angle_rotation += game->player.rotate_direction * game->player.rotate_speed;
	game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
}

void rotate_left(t_game *game)
{
	game->player.rotate_direction = -1;
	game->player.angle_rotation += game->player.rotate_direction * game->player.rotate_speed;
	game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
}

void open_door(t_game *game)
{
	int i;
	int midd_index;
	double distance;
	t_ray *midd_ray;
	
	midd_index = game->rays_number / 2;
	midd_ray = &game->rays[midd_index];
	i = 0;
	if (midd_ray->foundDoor)
	{
		distance = calculate_distance(game->player.position_x, game->player.position_y, midd_ray->wallHitX, midd_ray->wallHitY);
		int gridd_x = (midd_ray->wallHitX / UNIT_SIZE);
		int gridd_y = (midd_ray->wallHitY / UNIT_SIZE);
		while (i < doors_counter(game))
		{
			if (gridd_x == game->doors[i].x && gridd_y == game->doors[i].y)
			{
				printf("------> x: %d y: %d\n", game->doors[i].x, game->doors[i].y);
			}
			i++;
		}
	}
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
		backward_move(game);
	else if (key.key == MLX_KEY_W && (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		forward_move(game);
	else if (key.key == MLX_KEY_F && key.action == MLX_PRESS)
		open_door(game);
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	rebuild_game(game);
}
