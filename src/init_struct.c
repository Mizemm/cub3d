/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:16:55 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/18 00:07:46 by asalmi           ###   ########.fr       */
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
				game->player.position_x = (j * UNIT_SIZE) + 15;
				game->player.position_y = (i * UNIT_SIZE) + 15;
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
	game->map = malloc(sizeof(char *) * (15));
	if (!game->map)
		return ;
	game->map = get_map(game->map);
	game->WIDTH = get_width(game->map);
	game->HEIGHT = get_height(game->map);
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	game->player.rotate_speed = 5 * (M_PI / 180);
	game->player.move_speed = 5;
	game->player.angle_rotation = M_PI / 2;
	game->rays_number = game->WIDTH * UNIT_SIZE;
	game->rays = malloc(sizeof(t_ray) * game->rays_number);
	// if (!game->rays)
	// {
	// 	free(game);
	// 	return ;
	// }
	game->rays->color = 0x58179c8a;
	mlx = mlx_init(game->WIDTH * UNIT_SIZE, game->HEIGHT * UNIT_SIZE, "cub3d", false);
	game->mlx = mlx;
	if (!mlx)
		return ;
	find_player(game);
}
