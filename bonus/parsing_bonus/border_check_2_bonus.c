/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:40:54 by mizem             #+#    #+#             */
/*   Updated: 2025/02/24 20:50:22 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

int	mini_border_check(t_game *game, int y, int x)
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
	return (0);
}

int	border_check(t_game *game, int y, int x)
{
	if (mini_border_check(game, y, x) == 1)
		return (1);
	if (x == 0 && (game->map[y][x] == '0' || game->map[y][x] == 'N' 
		|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
			|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
				|| game->map[y][x] == 'C'))
		return (1);
	if (((game->map[y][x] == '0' || game->map[y][x] == 'N' 
		|| game->map[y][x] == 'S' || game->map[y][x] == 'W' 
		|| game->map[y][x] == 'E' || game->map[y][x] == 'O' 
		|| game->map[y][x] == 'C')) && checker(game, x, y) == 1)
		return (1);
	return (0);
}
