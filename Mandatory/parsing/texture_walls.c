/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2325/02/04 23:36:40 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 19:46:25 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_we(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localy;
	int		posx;
	int		posy;

	localy = ((ray[i].wallHitY / UNIT_SIZE) 
			- floor(ray[i].wallHitY / UNIT_SIZE)) 
		* game->textures->wall_texture[3]->width;
	posx = (int)localy;
	posy = (int)(((y - game->textures->walltopPixel) 
				/ game->textures->p_wall_height) 
			* game->textures->wall_texture[3]->height);
	texture_index = (posy * game->textures->wall_texture[3]->width + posx) * 4;
	mlx_put_pixel(game->image, i, y,
		color(&game->textures->wall_texture[3]->pixels[texture_index]));
}

void	render_ea(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localy;
	int		posx;
	int		posy;

	localy = ((ray[i].wallHitY / UNIT_SIZE) 
			- floor(ray[i].wallHitY / UNIT_SIZE)) 
		* game->textures->wall_texture[1]->width;
	posx = (int)localy;
	posy = (int)(((y - game->textures->walltopPixel) 
				/ game->textures->p_wall_height) 
			* game->textures->wall_texture[1]->height);
	texture_index = (posy * game->textures->wall_texture[1]->width + posx) * 4;
	mlx_put_pixel(game->image, i, y,
		color(&game->textures->wall_texture[1]->pixels[texture_index]));
}

void	render_so(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localx;
	int		posx;
	int		posy;

	localx = ((ray[i].wallHitX / UNIT_SIZE) 
			- floor(ray[i].wallHitX / UNIT_SIZE)) 
		* game->textures->wall_texture[2]->width;
	posx = (int)localx;
	posy = (int)(((y - game->textures->walltopPixel) 
				/ game->textures->p_wall_height) 
			* game->textures->wall_texture[2]->height);
	texture_index = (posy * game->textures->wall_texture[2]->width + posx) * 4;
	mlx_put_pixel(game->image, i, y,
		color(&game->textures->wall_texture[2]->pixels[texture_index]));
}

void	render_no(t_game *game, t_ray *ray, int i, int y)
{
	int		texture_index;
	double	localx;
	int		posx;
	int		posy;

	localx = ((ray[i].wallHitX / UNIT_SIZE) 
			- floor(ray[i].wallHitX / UNIT_SIZE)) 
		* game->textures->wall_texture[0]->width;
	posx = (int)localx;
	posy = (int)(((y - game->textures->walltopPixel) 
				/ game->textures->p_wall_height) 
			* game->textures->wall_texture[0]->height);
	texture_index = (posy * game->textures->wall_texture[0]->width + posx) * 4;
	mlx_put_pixel(game->image, i, y,
		color(&game->textures->wall_texture[0]->pixels[texture_index]));
}
