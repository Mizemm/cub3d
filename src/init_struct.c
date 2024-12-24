/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:16:55 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/24 15:06:38 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void find_player(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				game->player.position_x = (j * 30) + 15;
				game->player.position_y = (i * 30) + 15;
			}
			j++;
		}
		// printf("player_x: %f\n", game->player.position_x);
		// printf("player_y: %f\n", game->player.position_y);
		i++;
	}
}

void init_struct(t_game *game)
{
	game->player.position_x = 0;
	game->player.position_y = 0;
	find_player(game);
}