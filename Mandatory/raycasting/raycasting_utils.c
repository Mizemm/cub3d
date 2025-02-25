/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 00:47:05 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 22:19:29 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	check_vert_wall(t_game *game, double checkStepX, double checkStepY)
{
	if (is_wall(game, checkStepX, checkStepY))
	{
		game->vertical.vert_wall_hitx = game->vertical.next_vert_stepx;
		game->vertical.vert_wall_hity = game->vertical.next_vert_stepy;
		game->vertical.found_vert_wall = true;
		return (true);
	}
	return (false);
}

bool	check_horz_wall(t_game *game, double checkStepX, double checkStepY)
{
	if (is_wall(game, checkStepX, checkStepY))
	{
		game->horizontal.horz_wall_hitx = game->horizontal.next_horz_stepx;
		game->horizontal.horz_wall_hity = game->horizontal.next_horz_stepy;
		game->horizontal.found_horz_wall = true;
		return (true);
	}
	return (false);
}
