/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/02 16:58:22 by asalmi           ###   ########.fr       */
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
	printf("--------- %f---------\n", angle);
	printf("y_intercept: %ld\n", game->horizontal.y_intercept);
	printf("x_intercept: %ld\n", game->horizontal.x_intercept);
	printf("x_step: %ld\n", game->horizontal.x_step);
	printf("y_step: %ld\n", game->horizontal.x_step);
}

void cast_rays(t_game *game)
{
	double angle;

	angle = normalize_angle(game->player.angle_rotation);
	horizontal_intersection(game, angle);
}
