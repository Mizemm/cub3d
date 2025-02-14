/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:36:40 by mizem             #+#    #+#             */
/*   Updated: 2025/02/15 00:36:39 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void render_NO(t_game *game, t_ray *ray, int i, int y)
{
    int texture_index;
    double localY;
	int posX;
	int posY;

    localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->wall_texture[0]->width;
    posX = (int)localY;
	posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->wall_texture[0]->width);
	texture_index = (posY * game->textures->wall_texture[0]->height + posX) * 4;
	mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[0]->pixels[texture_index]));
}
void render_EA(t_game *game, t_ray *ray, int i, int y)
{
    int texture_index;
    double localX;
	int posX;
	int posY;

    localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->wall_texture[1]->width;
    posX = (int)localX;
	posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->wall_texture[1]->height);
	texture_index = (posY * game->textures->wall_texture[1]->width + posX) * 4;
	mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[1]->pixels[texture_index]));
}
void render_SO(t_game *game, t_ray *ray, int i, int y)
{
    int texture_index;
    double localY;
	int posX;
	int posY;

	localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->wall_texture[2]->width;
    posX = (int)localY;
    posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->wall_texture[2]->height);
	texture_index = (posY * game->textures->wall_texture[2]->width + posX) * 4;
	mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[2]->pixels[texture_index]));
}
void render_WE(t_game *game, t_ray *ray, int i, int y)
{
    int texture_index;
    double localX;
	int posX;
	int posY;

	localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->wall_texture[3]->width;
    posX = (int)localX;
	posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->wall_texture[3]->height);
	texture_index = (posY * game->textures->wall_texture[3]->width + posX) * 4;
	mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[3]->pixels[texture_index]));
}

