/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:16:55 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 20:48:47 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				game->player.position_x = (j * UNIT_SIZE) + 15;
				game->player.position_y = (i * UNIT_SIZE) + 15;
			}
			j++;
		}
		i++;
	}
}

int	allocate_rays(t_game *game)
{
	game->rays = malloc(sizeof(t_ray) * game->rays_number);
	if (!game->rays)
	{
		free(game);
		game = NULL;
		return (1);
	}
	return (0);
}

int	allocate_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (!game->textures)
	{
		free(game);
		free(game->rays);
		game = NULL;
		game->rays = NULL;
		return (1);
	}
	return (0);
}

void	init_struct(t_game *game)
{
	mlx_t	*mlx;

	ft_memset(game, 0, sizeof(t_game));
	game->player.rotate_speed = 5 * (M_PI / 180);
	game->player.move_speed = MOVE_SPEED;
	game->rays_number = WIDTH;
	if (allocate_rays(game) == 1 || allocate_textures(game) == 1)
		return ;
	mlx_set_setting(0, 1);
	mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	game->mlx = mlx;
	if (!mlx)
		return ;
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if ((!game->image) || (mlx_image_to_window(game->mlx, game->image, 0,
				0) < 0))
		return ;
	game->minimap_width = 7 * UNIT_SIZE;
	game->minimap_height = 5 * UNIT_SIZE;
	game->minimap_img = mlx_new_image(game->mlx, game->minimap_width,
			game->minimap_height);
	if ((!game->minimap_img) || (mlx_image_to_window(game->mlx,
				game->minimap_img, 10, 10)) < 0)
		return ;
}
