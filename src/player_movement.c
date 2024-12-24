/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:24:27 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/24 22:24:38 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void right_move(t_game *game)
{
	double move_steps;

	move_steps = game->player.move_speed;
	game->player.position_x += cos(game->player.angl_rotation + M_PI / 2) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation + M_PI / 2) * move_steps;
}

void left_move(t_game *game)
{
	double move_steps;

	move_steps = game->player.move_speed;
	game->player.position_x -= cos(game->player.angl_rotation + M_PI / 2) * move_steps;
	game->player.position_y -= sin(game->player.angl_rotation + M_PI / 2) * move_steps;
}

void down_move(t_game *game)
{
	double move_steps;

	game->player.move_direction = -1;
	move_steps = game->player.move_direction * game->player.move_speed;
	game->player.position_x += cos(game->player.angl_rotation) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation) * move_steps;
}

void up_move(t_game *game)
{
	double move_steps;

	game->player.move_direction = 1;
	move_steps = game->player.move_direction * game->player.move_speed;
	game->player.position_x += cos(game->player.angl_rotation) * move_steps;
	game->player.position_y += sin(game->player.angl_rotation) * move_steps;
}
