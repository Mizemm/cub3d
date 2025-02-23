/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:55:49 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/23 02:37:47 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_doors(t_game *game, double x, double y)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = floor(x / UNIT_SIZE);
	y_tmp = floor(y / UNIT_SIZE);
	if (x_tmp < 0 || y_tmp < 0 || x_tmp >= ft_strlen(game->map[y_tmp])
		|| y_tmp >= game->height)
		return (false);
	return (game->map[y_tmp][x_tmp] == 'C');
}

bool	is_openDoor(t_game *game, double x, double y)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = floor(x / UNIT_SIZE);
	y_tmp = floor(y / UNIT_SIZE);
	if (x_tmp < 0 || y_tmp < 0 || x_tmp >= ft_strlen(game->map[y_tmp])
		|| y_tmp >= game->height)
		return (false);
	return (game->map[y_tmp][x_tmp] == 'O');
}

int	check_for_close(t_game *game, int door_x, int door_y)
{
	int	player_x;
	int	player_y;

	player_x = floor(game->player.position_x / UNIT_SIZE);
	player_y = floor(game->player.position_y / UNIT_SIZE);
	if (abs(door_x - player_x) <= 2 && abs(door_y - player_y) <= 2)
		return (1);
	return (0);
}

void	check_for_open(t_game *game, int grid_x, int grid_y)
{
	int	i;

	i = -1;
	while (++i < doors_counter(game))
	{
		if (grid_x == game->doors[i].x && grid_y == game->doors[i].y
			&& game->doors[i].is_closed)
		{
			game->map[grid_y][grid_x] = 'O';
			game->doors[i].is_closed = false;
			break ;
		}
	}
}
