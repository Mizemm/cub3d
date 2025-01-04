/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/04 21:04:06 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void horizontal_intersection(t_game *game, double angle)
{
	if (is_facing_down(angle))
		game->horizontal.y_intercept = floor(game->player.position_y / UNIT_SIZE) * UNIT_SIZE + UNIT_SIZE;
	else
		game->horizontal.y_intercept = floor(game->player.position_y / UNIT_SIZE) * UNIT_SIZE - 1;
	game->horizontal.x_intercept = ((game->horizontal.y_intercept - game->player.position_y) / tan(angle)) + game->player.position_x;
	game->horizontal.y_step = UNIT_SIZE;
	if (is_facing_up(angle))
		game->horizontal.y_step *= -1;
	game->horizontal.x_step = UNIT_SIZE / tan(angle);
	if (is_facing_left(angle) && game->horizontal.x_step > 0)
		game->horizontal.x_step *= -1;
	else if (is_facing_right(angle) && game->horizontal.x_step < 0)
		game->horizontal.x_step *= -1;
	double nextHorzStepX = game->horizontal.x_intercept;
	double nextHorzStepY = game->horizontal.y_intercept;
	while (nextHorzStepX >= 0 && nextHorzStepX <= game->WIDTH * UNIT_SIZE 
		&& nextHorzStepY >= 0 && nextHorzStepY <= game->HEIGHT * UNIT_SIZE)
	{
		if (is_wall(game, nextHorzStepX, nextHorzStepY))
		{ 
			game->horizontal.horzWallHitX = nextHorzStepX;
			game->horizontal.horzWallHitY = nextHorzStepY;
			break;
		}
		nextHorzStepX += game->horizontal.x_step;
		nextHorzStepY += game->horizontal.y_step;
	}
}

// void vertical_intersection(t_game *game, double angle)
// {
	
// }

void cast_rays(t_game *game)
{
	double angle;

	angle = normalize_angle(game->player.angle_rotation);
	horizontal_intersection(game, angle);
}
