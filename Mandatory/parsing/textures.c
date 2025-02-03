 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:10:03 by mizem             #+#    #+#             */
/*   Updated: 2025/02/03 22:55:10 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t color(uint8_t *arr)
{
	return ((arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | arr[3]);
}

void load_textures(t_game *game)
{
    game->textures->wall_texture[0] = mlx_load_png("/Users/mizem/Desktop/curs/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[1] = mlx_load_png("/Users/mizem/Desktop/curs/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[2] = mlx_load_png("/Users/mizem/Desktop/curs/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[3] = mlx_load_png("/Users/mizem/Desktop/curs/cub3d/Mandatory/images/wall.png");
    if (!game->textures->wall_texture[0] 
    || !game->textures->wall_texture[1] 
    || !game->textures->wall_texture[2] 
    || !game->textures->wall_texture[3])
        exit (1);
}
void render_wall(t_game *game, t_ray *ray)
{
	int i;
	double localX;
	double localY;
	int texture_index;
	int posX;
	int posY;
	int terp;
	
	terp = 0;
	i = 0;
	double projection_distance = (WIDTH / 2) / tan(FOV / 2);
	while (i < game->rays_number)
	{
		if (ray[i].foundHorz)
        {
            localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->wall_texture[0]->width;
            posX = (int)localX;
        }
		if (ray[i].foundVert)
        {
            localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->wall_texture[0]->height;
            posX = (int)localY;
        }
		double p_wall_height = (UNIT_SIZE / ray[i].distance) * projection_distance;
		int walltopPixel = (HEIGHT / 2) - (p_wall_height / 2);
		int wallbuttomPixel = (HEIGHT / 2) + (p_wall_height / 2);
		int y = walltopPixel;
		terp = depth_color(ray[i].distance, terp);
		while (y < wallbuttomPixel)
		{
            texture_index = 0;
			if (ray[i].foundDoor)
			{
				if (y >=0 && y < HEIGHT)
					mlx_put_pixel(game->image, i, y, rgbt_color(107, 229, 184, terp));
			}
			else if (ray[i].foundHorz)
			{
				if (y >= 0 && y < HEIGHT)
				{
					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[0]->height);
					texture_index = (posY * game->textures->wall_texture[0]->width + posX) * 4;
						mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[0]->pixels[texture_index]));

				}
			}
			else if (ray[i].foundVert)
			{
				if (y >= 0 && y < HEIGHT)
				{
					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[0]->height);
					texture_index = (posY * game->textures->wall_texture[0]->width + posX) * 4;
						mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[0]->pixels[texture_index]));
					
				}
			}
			y++;
		}
		i++;
	}

}