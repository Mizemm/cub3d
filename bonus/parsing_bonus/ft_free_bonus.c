/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:36:14 by mizem             #+#    #+#             */
/*   Updated: 2025/02/24 20:50:41 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_textures(t_game *game)
{
	if (game->textures->wall_texture[0])
		mlx_delete_texture(game->textures->wall_texture[0]);
	if (game->textures->wall_texture[1])
		mlx_delete_texture(game->textures->wall_texture[1]);
	if (game->textures->wall_texture[2])
		mlx_delete_texture(game->textures->wall_texture[2]);
	if (game->textures->wall_texture[3])
		mlx_delete_texture(game->textures->wall_texture[3]);
	if (game->textures->door_texture[0])
		mlx_delete_texture(game->textures->door_texture[0]);
	if (game->textures->weapon_texture[0])
		mlx_delete_texture(game->textures->weapon_texture[0]);
	if (game->textures->weapon_texture[1])
		mlx_delete_texture(game->textures->weapon_texture[1]);
	if (game->textures->crosshair_texture[0])
		mlx_delete_texture(game->textures->crosshair_texture[0]);
	if (game->textures)
	{
		free(game->textures);
		game->textures = NULL;
	}
}

void	free_all(t_game *game)
{
	free_textures(game);
	if (game->elements)
		ft_free(game->elements);
	if (game->map)
		ft_free(game->map);
	if (game->no_path)
		free(game->no_path);
	if (game->so_path)
		free(game->so_path);
	if (game->we_path)
		free(game->we_path);
	if (game->ea_path)
		free(game->ea_path);
	if (game->floor_color)
		free(game->floor_color);
	if (game->ceiling_color)
		free(game->ceiling_color);
	if (game->trash)
		free(game->trash);
	if (game->rays)
	{
		free(game->rays);
		game->rays = NULL;
	}
	if (game->doors)
	{
		free(game->doors);
		game->doors = NULL;
	}
	if (game->minimap_img)
	{
		mlx_delete_image(game->mlx, game->minimap_img);
		game->minimap_img = NULL;
	}
	if (game->image)
	{
		mlx_delete_image(game->mlx, game->image);
		game->image = NULL;
	}
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	free(game);
}
