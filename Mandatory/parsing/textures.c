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

void	load_textures(t_game *game)
{
	game->textures->wall_texture[0] = mlx_load_png(game->no_path);
	game->textures->wall_texture[1] = mlx_load_png(game->ea_path);
	game->textures->wall_texture[2] = mlx_load_png(game->so_path);
	game->textures->wall_texture[3] = mlx_load_png(game->we_path);
	if (!game->textures->wall_texture[0] 
		|| !game->textures->wall_texture[1] 
		|| !game->textures->wall_texture[2] 
		|| !game->textures->wall_texture[3])
		exit (1);
}

void	render_textures_2(t_game *game, t_ray *ray, int y, int i)
{
	while (y < game->textures->wall_buttom_pixel)
	{
		if (ray[i].found_no && (y >= 0 && y < HEIGHT))
			render_no(game, ray, i, y);
		if (ray[i].found_so && (y >= 0 && y < HEIGHT))
			render_so(game, ray, i, y);
		if (ray[i].found_ea && (y >= 0 && y < HEIGHT))
			render_ea(game, ray, i, y);
		if (ray[i].found_we && (y >= 0 && y < HEIGHT))
			render_we(game, ray, i, y);
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
		game->textures->wall_top_pixel = 
			(HEIGHT / 2) - (game->textures->p_wall_height / 2);
		game->textures->wall_buttom_pixel = 
			(HEIGHT / 2) + (game->textures->p_wall_height / 2);
		y = game->textures->wall_top_pixel;
		render_textures_2(game, ray, y, i);
		i++;
	}
}
