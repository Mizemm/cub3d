/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:35:24 by mizem             #+#    #+#             */
/*   Updated: 2025/02/21 20:09:54 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	checker(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] == ' ' || game->map[y][x + 1] == '\n' 
		|| game->map[y][x + 1] == '\0')
		return (1);
	if (game->map[y][x - 1] == ' ' || game->map[y][x - 1] == '\n' 
		|| game->map[y][x - 1] == '\0')
		return (1);
	if (game->map[y - 1][x] == ' ' || game->map[y - 1][x] == '\n' 
		|| game->map[y - 1][x] == '\0')
		return (1);
	if (game->map[y + 1][x] == ' ' || game->map[y + 1][x] == '\n' 
		|| game->map[y + 1][x] == '\0')
		return (1);
	return (0);
}

int	border_check(t_game *game, int y, int x)
{
	if (y == 0)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0' || game->map[y][x] == 'N' 
				|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
					|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
						|| game->map[y][x] == 'C')
				return (1);
			x++;
		}
	}
	if (x == 0 && (game->map[y][x] == '0' || game->map[y][x] == 'N' 
		|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
			|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
				|| game->map[y][x] == 'C'))
		return (1);
	if (y == game->height - 1)
	{
		while (game->map[y][x])
		{
			if ((game->map[y][x] == '0' || game->map[y][x] == 'N' 
			|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
			|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
			|| game->map[y][x] == 'C'))
				return (1);
			x++;
		}
	}
	if (((game->map[y][x] == '0' || game->map[y][x] == 'N' 
		|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
		|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
		|| game->map[y][x] == 'C')) && checker(game, x, y) == 1)
		return (1);
	return (0);
}

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
				&& game->map[y][x] != 'O' && game->map[y][x]
				!= 'C' && game->map[y][x] != ' ' && game->map[y][x] != '\n' 
				&& game->map[y][x] != '\t')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
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
		y++;
	}
	if (flag != 1)
		return (1);
	return (0);
}

int	map_checker_3(t_game *game)
{
	int	x;
	int	y;
	int	flag;
	int	flag_2;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		flag = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C' && (game->map[y][x + 1] == '0' 
			&& game->map[y][x - 1] == '0'))
				flag++;
			if (game->map[y][x] == 'C' && (game->map[y + 1][x] == '0' 
			&& game->map[y - 1][x] == '0'))
				flag++;
			if (flag == 2)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return (1);
		i++;
	}
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

int	borders(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	if (map_checker(game) == 1 || map_checker_2(game) == 1 
		|| map_checker_3(game) == 1 || map_checker_4(game) == 1)
		return (1);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (border_check(game, y, x) == 1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
