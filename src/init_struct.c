/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:16:55 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/24 22:20:04 by asalmi           ###   ########.fr       */
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
		i++;
	}
}

void init_struct(t_game *game)
{
	mlx_t *mlx;

	// Zero-initialize the entire structure -> use memset
	game->map = malloc(sizeof(char *) * (10 + 1));
	if (!game->map)
		return ;
	game->map = get_map(game->map);
	game->WIDTH = get_width(game->map);
	game->HEIGHT = get_height(game->map);
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	game->player.rotate_speed = 5 * (M_PI / 180);
	game->player.move_speed = 5;
	game->player.angl_rotation = M_PI / 2;
	mlx = mlx_init(game->WIDTH * 30, game->HEIGHT * 30, "cub3d", false);
	game->mlx = mlx;
	if (!mlx)
		return ;
	game->player.position_x = 0;
	game->player.position_y = 0;
	find_player(game);
}
