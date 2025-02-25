/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:35:24 by mizem             #+#    #+#             */
/*   Updated: 2025/02/24 20:50:26 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
