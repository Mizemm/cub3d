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
	// return ((arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | 0xFF);
	static int i =0;
	uint32_t color = (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | 0xFF;


	if (i == 0)
	{
		printf("av[0: %d, av1: %d , av2 : %d \n", arr[0], arr[1], arr[2]);
		printf("COLOR : %X\n", color);
		i++;
	}
	return (color);
}

void load_textures(t_game *game)
{
    game->textures->wall_texture[0] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[1] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[2] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/wall.png");
    game->textures->wall_texture[3] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/wall.png");
    game->textures->door_texture[0] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/door.png");
    game->textures->weapon_texture[0] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/w1.png");
    game->textures->weapon_texture[1] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/w2.png");
    game->textures->crosshair_texture[0] = mlx_load_png("/Users/asalmi/cursus/cub3d/Mandatory/images/crosshair.png");
	game->textures->weapon_img[0] = mlx_texture_to_image(game->mlx, game->textures->weapon_texture[0]);
	game->textures->weapon_img[1] = mlx_texture_to_image(game->mlx, game->textures->weapon_texture[1]);
	game->textures->crosshair_img[0] = mlx_texture_to_image(game->mlx, game->textures->crosshair_texture[0]);
    if (!game->textures->wall_texture[0] 
    || !game->textures->wall_texture[1] 
    || !game->textures->wall_texture[2] 
    || !game->textures->wall_texture[3] 
	|| !game->textures->door_texture[0] 
	|| !game->textures->weapon_texture[0] 
	|| !game->textures->weapon_texture[1])
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
	double p_wall_height;
	int walltopPixel;
	int wallbuttomPixel;
	int y;
	double projection_distance = (WIDTH / 2) / tan(FOV / 2);
	terp = 0;
	i = 0;
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
		p_wall_height = (UNIT_SIZE / ray[i].distance) * projection_distance;
		walltopPixel = (HEIGHT / 2) - (p_wall_height / 2);
		wallbuttomPixel = (HEIGHT / 2) + (p_wall_height / 2);
		y = walltopPixel;
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

void	render_weapon(t_game *game)
{
	int y = HEIGHT;
	int y2 = HEIGHT - 150;
    int x = 400;
	mlx_image_to_window(game->mlx, game->textures->weapon_img[0], y, x);
	mlx_image_to_window(game->mlx, game->textures->weapon_img[1], y2, x);
	mlx_image_to_window(game->mlx, game->textures->crosshair_img[0], WIDTH / 2, HEIGHT / 2);
	game->textures->weapon_img[1]->enabled = false;
}

void	animate_weapon(t_game *game)
{
	game->textures->weapon_img[0]->enabled = false;
	game->textures->weapon_img[1]->enabled = true;

}

void	deanimate_weapon(t_game *game)
{
	game->textures->weapon_img[1]->enabled = false;
	game->textures->weapon_img[0]->enabled = true;
}
