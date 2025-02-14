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
	uint32_t color = (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | 0xFF;
	return (color);
}

void load_textures(t_game *game)
{
    game->textures->wall_texture[0] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/NO.png");
    game->textures->wall_texture[1] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/EA.png");
    game->textures->wall_texture[2] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/SO.png");
    game->textures->wall_texture[3] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/WE.png");
    game->textures->door_texture[0] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/door.png");
    game->textures->weapon_texture[0] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/w1.png");
    game->textures->weapon_texture[1] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/w2.png");
    game->textures->crosshair_texture[0] = mlx_load_png("/Users/mizem/Desktop/cursus/cub3d/Mandatory/images/crosshair.png");
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

void render_textures(t_game *game, t_ray *ray)
{
	int i;
	int y;
	double localX;
	double localY;
	int posX;
	int posY;
	int texture_index;

	i = 0;
	game->textures->projection_distance = (WIDTH / 2) / tan(FOV / 2);
	while (i < game->rays_number)
	{
		game->textures->p_wall_height = (UNIT_SIZE / ray[i].distance) * game->textures->projection_distance;
		game->textures->walltopPixel = (HEIGHT / 2) - (game->textures->p_wall_height / 2);
		game->textures->wallbuttomPixel = (HEIGHT / 2) + (game->textures->p_wall_height / 2);
		y = game->textures->walltopPixel;
		while (y < game->textures->wallbuttomPixel)
		{
            texture_index = 0;
			if (ray[i].foundNO && (y >= 0 && y < HEIGHT))
				render_NO(game, ray, i, y);
			else if (ray[i].foundEA && (y >= 0 && y < HEIGHT))
				render_EA(game, ray, i, y);
			else if (ray[i].foundWE && (y >= 0 && y < HEIGHT))
				render_WE(game, ray, i, y);
			else if (ray[0].foundSO && (y >= 0 && y < HEIGHT))
				render_SO(game, ray, i, y);
			else if (ray[i].foundHorzDoor)
			{
				if (y >= 0 && y < HEIGHT)
				{
        	    	localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->door_texture[0]->width;
        		    posX = (int)localX;
					posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->door_texture[0]->height);
					texture_index = (posY * game->textures->door_texture[0]->width + posX) * 4;
					mlx_put_pixel(game->image, i, y, color(&game->textures->door_texture[0]->pixels[texture_index]));

				}
			}
			else if (ray[i].foundVertDoor)
			{
				if (y >= 0 && y < HEIGHT)
				{
            		localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->door_texture[0]->width;
        	    	posX = (int)localY;
					posY = (int)(((y - game->textures->walltopPixel) / game->textures->p_wall_height) * game->textures->door_texture[0]->width);
					texture_index = (posY * game->textures->door_texture[0]->height + posX) * 4;
					mlx_put_pixel(game->image, i, y, color(&game->textures->door_texture[0]->pixels[texture_index]));
				}
			}
			y++;
		}
		i++;
	}
}


// void render_textures(t_game *game, t_ray *ray)
// {
// 	int i;
// 	double p_wall_height;
// 	int walltopPixel;
// 	int wallbuttomPixel;
// 	int y;
// 	double localX;
// 	double localY;
// 	int posX;
// 	int posY;
// 	int texture_index;
// 	double projection_distance;

// 	i = 0;
// 	projection_distance = (WIDTH / 2) / tan(FOV / 2);
// 	while (i < game->rays_number)
// 	{
// 		p_wall_height = (UNIT_SIZE / ray[i].distance) * projection_distance;
// 		walltopPixel = (HEIGHT / 2) - (p_wall_height / 2);
// 		wallbuttomPixel = (HEIGHT / 2) + (p_wall_height / 2);
// 		y = walltopPixel;
// 		while (y < wallbuttomPixel)
// 		{
//             texture_index = 0;
// 				if (ray[i].foundEA && (y >= 0 && y < HEIGHT))
// 				{
// 					localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->wall_texture[1]->width;
//            			posX = (int)localX;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[1]->height);
// 					texture_index = (posY * game->textures->wall_texture[1]->width + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[1]->pixels[texture_index]));
// 				}
// 				else if (ray[i].foundWE && (y >= 0 && y < HEIGHT))
// 				{
// 					localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->wall_texture[3]->width;
//            			posX = (int)localX;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[3]->height);
// 					texture_index = (posY * game->textures->wall_texture[3]->width + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[3]->pixels[texture_index]));
// 				}
// 				else if (ray[i].foundNO && (y >= 0 && y < HEIGHT))
// 				{
// 					localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->wall_texture[0]->width;
//             		posX = (int)localY;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[0]->height);
// 					texture_index = (posY * game->textures->wall_texture[0]->width + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[0]->pixels[texture_index]));
					
// 				}
// 				else if (ray[0].foundSO && (y >= 0 && y < HEIGHT))
// 				{
// 					localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->wall_texture[2]->width;
//             		posX = (int)localY;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->wall_texture[2]->height);
// 					texture_index = (posY * game->textures->wall_texture[2]->width + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->wall_texture[2]->pixels[texture_index]));
					
// 				}
// 			if (ray[i].foundHorzDoor)
// 			{
// 				if (y >= 0 && y < HEIGHT)
// 				{
//         	    	localX = ((ray[i].wallHitX / UNIT_SIZE) - floor(ray[i].wallHitX / UNIT_SIZE)) * game->textures->door_texture[0]->width;
//         		    posX = (int)localX;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->door_texture[0]->height);
// 					texture_index = (posY * game->textures->door_texture[0]->width + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->door_texture[0]->pixels[texture_index]));

// 				}
// 			}
// 			if (ray[i].foundVertDoor)
// 			{
// 				if (y >= 0 && y < HEIGHT)
// 				{
//             		localY = ((ray[i].wallHitY / UNIT_SIZE) - floor(ray[i].wallHitY / UNIT_SIZE)) * game->textures->door_texture[0]->width;
//         	    	posX = (int)localY;
// 					posY = (int)(((y - walltopPixel) / p_wall_height) * game->textures->door_texture[0]->width);
// 					texture_index = (posY * game->textures->door_texture[0]->height + posX) * 4;
// 					mlx_put_pixel(game->image, i, y, color(&game->textures->door_texture[0]->pixels[texture_index]));
// 				}
// 			}
// 			y++;
// 		}
// 		i++;
// 	}

// }

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
