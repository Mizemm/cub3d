/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:16:55 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/22 01:16:05 by asalmi           ###   ########.fr       */
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

	game->width = 0;
	game->height = 0;
	game->x_draw = 0;
	game->y_draw = 0;
	game->minimap_width = 0;
	game->minimap_height = 0;
	game->elements = NULL;
	game->map = NULL;
	game->no_path = NULL;
	game->so_path = NULL;
	game->we_path = NULL;
	game->ea_path = NULL;
	game->floor_color = NULL;
	game->ceiling_color = NULL;
	game->trash = NULL;
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	game->player.rotate_speed = 5 * (M_PI / 180);
	game->player.move_speed = MOVE_SPEED;
	game->rays_number = WIDTH;
	game->rays = malloc(sizeof(t_ray) * game->rays_number);
	game->textures = malloc(sizeof(t_textures));
	if (!game->rays)
	{
		free(game);
		return ;
	}
	game->rays->foundHorz = false;
	game->rays->foundVert = false;
	game->rays->foundHorzDoor = false;
	game->rays->foundVertDoor = false;
	game->rays->openHorzDoor = false;
	game->rays->openVertDoor = false;
	game->horizontal.x_open = 0;
	game->horizontal.y_open = 0;
	game->vertical.x_open = 0;
	game->vertical.y_open = 0;
	game->player.position_x = 0;
	game->player.position_y = 0;
	game->minimap_width = 7 * UNIT_SIZE;
	game->minimap_height = 5 * UNIT_SIZE;
	mlx_set_setting(0, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		return ;
	game->mlx = mlx;
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if ((!game->image) || (mlx_image_to_window(game->mlx, game->image, 0, 0) < 0))
		return ;
	game->minimap_img = mlx_new_image(game->mlx, game->minimap_width, game->minimap_height);
	if ((!game->minimap_img) || (mlx_image_to_window(game->mlx, game->minimap_img, 10, 10)) < 0)
		return ;
}
