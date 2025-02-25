/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   texture_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:18:41 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 19:38:47 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	render_horzdoor(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localx;
	int		posx;
	int		posy;

	localx = ((ray[i].wall_hitx / UNIT_SIZE) 
			- floor(ray[i].wall_hitx / UNIT_SIZE)) 
		* game->textures->door_texture[0]->width;
	posx = (int)localx;
	posy = (int)(((y - game->textures->wall_top_pixel) 
				/ game->textures->p_wall_height) 
			* game->textures->door_texture[0]->height);
	texture_index = (posy * game->textures->door_texture[0]->width + posx) * 4;
	mlx_put_pixel(game->image, i, y, 
		color(&game->textures->door_texture[0]->pixels[texture_index]));
}

void	render_vertdoor(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localy;
	int		posx;
	int		posy;

	localy = ((ray[i].wall_hity / UNIT_SIZE) 
			- floor(ray[i].wall_hity / UNIT_SIZE)) 
		* game->textures->door_texture[0]->width;
	posx = (int)localy;
	posy = (int)(((y - game->textures->wall_top_pixel)
				/ game->textures->p_wall_height)
			* game->textures->door_texture[0]->width);
	texture_index = (posy * game->textures->door_texture[0]->height + posx) * 4;
	mlx_put_pixel(game->image, i, y,
		color(&game->textures->door_texture[0]->pixels[texture_index]));
}
