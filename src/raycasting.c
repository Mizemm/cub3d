/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/01 19:04:22 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool is_facing_down(double angle)
{
	return (angle > 0 && angle < M_PI);
}

bool is_facing_up(double angle)
{
	return (angle > M_PI && angle < 2 * M_PI);
}

bool is_facing_right(double angle)
{
	return (angle > 3 * M_PI / 2 || angle < M_PI / 2);
}

bool is_facing_left(double angle)
{
	return (angle > M_PI / 2 && angle < 3 * M_PI / 2);
}

void horizontal_intersection(t_game *game)
{
	if (is_facing_down(game->player.angle_rotation))
		game->horizontal.y_intercept = floor(game->player.position_y / UNIT_SIZE) * UNIT_SIZE + UNIT_SIZE;
	else
		game->horizontal.y_intercept = floor(game->player.position_y / UNIT_SIZE) * UNIT_SIZE - 1;
	game->horizontal.x_intercept = ((game->horizontal.y_intercept - game->player.position_y) / tan(game->player.angle_rotation)) + game->player.position_x;
	game->horizontal.y_step = UNIT_SIZE;
	if (is_facing_up(game->player.angle_rotation))
		game->horizontal.y_step *= -1;
	game->horizontal.x_step = UNIT_SIZE / tan(game->player.angle_rotation);
	printf("xtep: %ld\n", game->horizontal.x_step);
}
