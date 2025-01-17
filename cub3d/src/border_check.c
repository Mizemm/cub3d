/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:35:24 by mizem             #+#    #+#             */
/*   Updated: 2025/01/15 21:01:28 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	flud_fill(char **map, int y, int x)
// {   
// 	int j = -1;
// 		while(map[++j])
//    	    	printf("%s", map[j]);
// 		printf("\n");
// 		printf("\n");
// 	map[y][x] = '1';
// 	if (y + 1 < count_height(map) && map[y + 1][x] != '1')
// 		flud_fill(map, y + 1, x);
// 	if (y - 1 >= 0 && map[y - 1][x] != '1')
// 		flud_fill(map, y - 1, x);
// 	if (x + 1 < count_width(map) && map[y][x + 1] != '1')
// 		flud_fill(map, y, x + 1);
// 	if (x - 1 >= 0 && map[y][x - 1] != '1')
// 		flud_fill(map, y, x - 1);
// }

int checker(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] == ' ' || game->map[y][x + 1] == '\n' || game->map[y][x + 1] == '\0')
		return (1);
	if (game->map[y][x - 1] == ' ' || game->map[y][x + 1] == '\n' || game->map[y][x + 1] == '\0')
		return (1);
	if (game->map[y - 1][x] == ' ' || game->map[y][x + 1] == '\n' || game->map[y][x + 1] == '\0')
		return (1);
	if (game->map[y + 1][x] == ' ' || game->map[y][x + 1] == '\n' || game->map[y][x + 1] == '\0')
		return (1);
	return (0);
}
int border_check(t_game *game, int y, int x)
{
	if (y == 0)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				return (1);
			x++;
		}
	}
	if (x == 0 && game->map[y][x] == '0')
		return (1);
	if (y == game->HEIGHT - 1)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				return (1);
			x++;
		}
	}
	if (game->map[y][x] == '0' && checker(game, x, y) == 1)
	{
		printf("<%s>\n", game->map[y]);	
		return (1);
	}
	return (0);
}

int	borders(t_game *game)
{
	int		x;
	int		y;

	y = 0;
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
