/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:45:21 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 20:49:09 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

double	normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

bool	is_wall(t_game *game, double x, double y)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = floor(x / UNIT_SIZE);
	y_tmp = floor(y / UNIT_SIZE);
	if (x_tmp < 0 || y_tmp < 0 || x_tmp >= ft_strlen(game->map[y_tmp])
		|| y_tmp >= game->height)
		return (false);
	return (game->map[y_tmp][x_tmp] == '1');
}

double	calculate_distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt((dx * dx) + (dy * dy)));
}

int	init_door(t_game *game)
{
	int	door_size;

	door_size = doors_counter(game);
	if (door_size <= 0)
	{
		game->doors = NULL;
		return (1);
	}
	game->doors = malloc(sizeof(t_doors) * (door_size));
	if (!game->doors)
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	doors_allocted(t_game *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	index = 0;
	if (init_door(game) == -1)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'O')
			{
				game->doors[index].x = x;
				game->doors[index].y = y;
				game->doors[index].is_closed = (game->map[y][x] == 'C');
				index++;
			}
			x++;
		}
		y++;
	}
}
