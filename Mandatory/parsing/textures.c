/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:08:47 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 20:10:11 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_textures_2(t_game *game)
{
	game->textures->door_texture[0] = mlx_load_png
		("/Users/asalmi/cursus/cub3d/Mandatory/images/door.png");
	game->textures->weapon_texture[0] = mlx_load_png
		("/Users/asalmi/cursus/cub3d/Mandatory/images/w1.png");
	game->textures->weapon_texture[1] = mlx_load_png
		("/Users/asalmi/cursus/cub3d/Mandatory/images/w2.png");
	game->textures->crosshair_texture[0] = mlx_load_png
		("/Users/asalmi/cursus/cub3d/Mandatory/images/crosshair.png");
	game->textures->weapon_img[0] = mlx_texture_to_image
		(game->mlx, game->textures->weapon_texture[0]);
	game->textures->weapon_img[1] = mlx_texture_to_image
		(game->mlx, game->textures->weapon_texture[1]);
	game->textures->crosshair_img[0] = mlx_texture_to_image
		(game->mlx, game->textures->crosshair_texture[0]);
}

void	load_textures(t_game *game)
{
	game->textures->wall_texture[0] = mlx_load_png(game->no_path);
	game->textures->wall_texture[1] = mlx_load_png(game->ea_path);
	game->textures->wall_texture[2] = mlx_load_png(game->so_path);
	game->textures->wall_texture[3] = mlx_load_png(game->we_path);
	load_textures_2(game);
	if (!game->textures->wall_texture[0] 
		|| !game->textures->wall_texture[1] 
		|| !game->textures->wall_texture[2] 
		|| !game->textures->wall_texture[3] 
		|| !game->textures->door_texture[0] 
		|| !game->textures->weapon_texture[0] 
		|| !game->textures->weapon_texture[1]
		|| !game->textures->crosshair_texture[0])
		exit (1);
}

void	render_textures_2(t_game *game, t_ray *ray, int y, int i)
{
	while (y < game->textures->wallbuttomPixel)
	{
		if (ray[i].foundNO && (y >= 0 && y < HEIGHT))
			render_no(game, ray, i, y);
		if (ray[i].foundSO && (y >= 0 && y < HEIGHT))
			render_so(game, ray, i, y);
		if (ray[i].foundEA && (y >= 0 && y < HEIGHT))
			render_ea(game, ray, i, y);
		if (ray[i].foundWE && (y >= 0 && y < HEIGHT))
			render_we(game, ray, i, y);
		if (ray[i].foundHorzDoor && (y >= 0 && y < HEIGHT))
			render_horzdoor(game, ray, i, y);
		if (ray[i].foundVertDoor && (y >= 0 && y < HEIGHT))
			render_vertdoor(game, ray, i, y);
		y++;
	}
}

void	render_textures(t_game *game, t_ray *ray)
{
	int	i;
	int	y;

	i = 0;
	game->textures->projection_distance = (WIDTH / 2) / tan(FOV / 2);
	while (i < game->rays_number)
	{
		game->textures->p_wall_height = 
			(UNIT_SIZE / ray[i].distance) * game->textures->projection_distance;
		game->textures->walltopPixel = 
			(HEIGHT / 2) - (game->textures->p_wall_height / 2);
		game->textures->wallbuttomPixel = 
			(HEIGHT / 2) + (game->textures->p_wall_height / 2);
		y = game->textures->walltopPixel;
		render_textures_2(game, ray, y, i);
		i++;
	}
}
