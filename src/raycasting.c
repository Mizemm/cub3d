/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/07 19:24:34 by asalmi           ###   ########.fr       */
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
			game->horizontal.foundHorzWall = true;
			game->horizontal.horzWallHitX = nextHorzStepX;
			game->horizontal.horzWallHitY = nextHorzStepY;
			break;
		}
		nextHorzStepX += game->horizontal.x_step;
		nextHorzStepY += game->horizontal.y_step;
	}
}

void vertical_intersection(t_game *game, double angle)
{
	if (is_facing_right(angle))
		game->vertical.x_intercept = (floor(game->player.position_x / UNIT_SIZE) * UNIT_SIZE) + UNIT_SIZE;
	else
		game->vertical.x_intercept = (floor(game->player.position_x / UNIT_SIZE) * UNIT_SIZE) - 1;
	game->vertical.y_intercept = ((game->vertical.x_intercept - game->player.position_x) * tan(angle)) + game->player.position_y;
	game->vertical.x_step = UNIT_SIZE;
	if (is_facing_left(angle))
		game->vertical.x_step *= -1;
	game->vertical.y_step = tan(angle) * UNIT_SIZE;
	if (is_facing_up(angle) && game->vertical.y_step > 0)
		game->vertical.y_step *= -1;
	else if (is_facing_down(angle) && game->vertical.y_step < 0)
		game->vertical.y_step *= -1;
	// printf("x intercept: %ld\n", game->vertical.x_intercept);
	// printf("y intercept: %ld\n", game->vertical.y_intercept);
	// printf("x step: %ld\n", game->vertical.x_step);
	// printf("y step: %ld\n", game->vertical.y_step);
	double nextVertStepX = game->vertical.x_intercept;
	double nextVertStepY = game->vertical.y_intercept;
	while (nextVertStepX >=0 && nextVertStepX <= game->WIDTH * UNIT_SIZE
		&& nextVertStepY >= 0 && nextVertStepY  <= game->HEIGHT * UNIT_SIZE)
	{
		if (is_wall(game, nextVertStepX, nextVertStepY))
		{
			// printf("--------------- test -----------\n");
			game->vertical.foundVertWall = true;
			game->vertical.vertWallHitX = nextVertStepX;
			game->vertical.vertWallHitY = nextVertStepY;
			break ;
		}
		nextVertStepX += game->vertical.x_step;
		nextVertStepY += game->vertical.y_step;
	}
}

void cast_rays(t_game *game)
{
	double angle;
	double vertical_distance;
	double horizontal_distance;

	vertical_distance = INT_MAX;
	horizontal_distance = INT_MAX;
	angle = normalize_angle(game->player.angle_rotation);
	horizontal_intersection(game, angle);
	vertical_intersection(game, angle);
	if (game->horizontal.foundHorzWall)
		horizontal_distance = calculate_distance(game->horizontal.horzWallHitX, game->horizontal.horzWallHitY, game->player.position_x, game->player.position_y);
	if (game->vertical.foundVertWall)
		vertical_distance = calculate_distance(game->vertical.vertWallHitX, game->vertical.vertWallHitY, game->player.position_x, game->player.position_y);
	if (horizontal_distance < vertical_distance)
	{
		game->wallHitX = game->horizontal.horzWallHitX;
		game->wallHitY = game->horizontal.horzWallHitY;
	}
	else
	{
		game->wallHitX = game->vertical.vertWallHitX;
		game->wallHitY = game->vertical.vertWallHitY;
	}
}
