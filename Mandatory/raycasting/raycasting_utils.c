/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:47:05 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 02:36:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_vert_wall(t_game *game, double checkStepX, double checkStepY)
{
	if (is_wall(game, checkStepX, checkStepY) || is_doors(game, checkStepX,
			checkStepY))
	{
		game->vertical.vert_wall_hitx = game->vertical.next_vert_stepx;
		game->vertical.vert_wall_hity = game->vertical.next_vert_stepy;
		game->vertical.found_vert_wall = true;
		return (true);
	}
	return (false);
}

void	check_vert_door(t_game *game, double checkStepX, double checkStepY,
		double angle)
{
	if (is_opendoor(game, checkStepX, checkStepY)
		&& angle == game->player.angle_rotation
		&& game->vertical.first_close == false)
	{
		game->vertical.x_open = (int)(game->vertical.next_vert_stepx
				/ UNIT_SIZE);
		game->vertical.y_open = (int)(game->vertical.next_vert_stepy
				/ UNIT_SIZE);
		game->vertical.open_vert_door = true;
		game->vertical.first_close = true;
	}
}

bool	check_horz_wall(t_game *game, double checkStepX, double checkStepY)
{
	if (is_wall(game, checkStepX, checkStepY) || is_doors(game, checkStepX,
			checkStepY))
	{
		game->horizontal.horz_wall_hitx = game->horizontal.next_horz_stepx;
		game->horizontal.horz_wall_hity = game->horizontal.next_horz_stepy;
		game->horizontal.found_horz_wall = true;
		return (true);
	}
	return (false);
}

void	check_horz_door(t_game *game, double checkStepX, double checkStepY,
		double angle)
{
	if (is_opendoor(game, checkStepX, checkStepY)
		&& angle == game->player.angle_rotation
		&& game->horizontal.first_close == false)
	{
		game->horizontal.x_open = (int)(game->horizontal.next_horz_stepx
				/ UNIT_SIZE);
		game->horizontal.y_open = (int)(game->horizontal.next_horz_stepy
				/ UNIT_SIZE);
		game->horizontal.open_horz_door = true;
		game->horizontal.first_close = true;
	}
}
