/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:11:16 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/23 01:59:37 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_right(t_game *game)
{
	game->player.rotate_direction = 1;
	game->player.angle_rotation += game->player.rotate_direction
		* game->player.rotate_speed;
	game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
}

void	rotate_left(t_game *game)
{
	game->player.rotate_direction = -1;
	game->player.angle_rotation += game->player.rotate_direction
		* game->player.rotate_speed;
	game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
}

void	handle_rotation(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_right(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_left(game);
}

void	handle_movement(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		right_move(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		left_move(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		backward_move(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		forward_move(game);
}

void	movement_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	handle_rotation(game);
	handle_movement(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_F))
		open_door(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_C))
		close_door(game);
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	rebuild_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
		animate_weapon(game);
	if (!mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
		deanimate_weapon(game);
}
