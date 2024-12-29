/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/29 21:26:11 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void horizontal_intersection(t_game *game)
{
	game->horizontal.y_intercept = floor(game->player.position_y / UNIT_SIZE) * UNIT_SIZE;
	game->horizontal.x_intercept = ((game->horizontal.y_intercept - game->player.position_y) / tan(game->player.angle_rotation)) + game->player.position_x;
	game->horizontal.y_step = UNIT_SIZE;
	game->horizontal.x_step = game->horizontal.y_step / tan(game->player.angle_rotation);
}