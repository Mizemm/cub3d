/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:58:18 by mizem             #+#    #+#             */
/*   Updated: 2025/02/25 22:23:41 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	map_checker(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' 
			&& game->map[y][x] != 'N' && game->map[y][x] != 'S' 
				&& game->map[y][x] != 'W' && game->map[y][x] != 'E' 
				&& game->map[y][x] != ' ' && game->map[y][x] != '\n' 
				&& game->map[y][x] != '\t')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	mini_map_checker(t_game *game, int y, int x, int flag)
{
	while (game->map[y][x])
	{
		if (game->map[y][x] == 'N')
		{
			game->player_direction = 'N';
			flag++;
		}
		if (game->map[y][x] == 'S')
		{
			game->player_direction = 'S';
			flag++;
		}
		if (game->map[y][x] == 'W')
		{
			game->player_direction = 'W';
			flag++;
		}
		if (game->map[y][x] == 'E')
		{
			game->player_direction = 'E';
			flag++;
		}
		x++;
	}
	return (flag);
}

int	map_checker_2(t_game *game)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (game->map[y])
	{
		x = 0;
		flag = mini_map_checker(game, y, x, flag);
		y++;
	}
	if (flag != 1)
		return (1);
	return (0);
}

int	map_checker_4(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		if (empty_line(game->map[y]) == 0 && (game->map[y + 1] 
				&& empty_line(game->map[y + 1]) == 1))
			return (1);
		y++;
	}
	return (0);
}
