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
    game->textures->wall_texture[0] = mlx_load_png(game->no_path);
    game->textures->wall_texture[1] = mlx_load_png(game->ea_path);
    game->textures->wall_texture[2] = mlx_load_png(game->so_path);
    game->textures->wall_texture[3] = mlx_load_png(game->we_path);
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
	|| !game->textures->weapon_texture[1]
	|| !game->textures->crosshair_texture[0])
        exit (1);
}
// void	render_textures_2(t_game *game, t_ray *ray, int y, )
void render_textures(t_game *game, t_ray *ray)
{
	int i;
	int y;
	
	i = 0;
	game->textures->projection_distance = (WIDTH / 2) / tan(FOV / 2);
	while (i < game->rays_number)
	{
		game->textures->p_wall_height = (UNIT_SIZE / ray[i].distance) * game->textures->projection_distance;
		game->textures->walltoppixel = (HEIGHT / 2) - (game->textures->p_wall_height / 2);
		game->textures->wallbuttompixel = (HEIGHT / 2) + (game->textures->p_wall_height / 2);
		y = game->textures->walltoppixel;
		while (y < game->textures->wallbuttompixel)
		{
			if (ray[i].found_no && (y >= 0 && y < HEIGHT))
				render_NO(game, ray, i, y);
			if (ray[i].found_so && (y >= 0 && y < HEIGHT))
				render_SO(game, ray, i, y);
			if (ray[i].found_ea && (y >= 0 && y < HEIGHT))
				render_EA(game, ray, i, y);
			if (ray[i].found_we && (y >= 0 && y < HEIGHT))
				render_WE(game, ray, i, y);
			if (ray[i].foundhorzdoor && (y >= 0 && y < HEIGHT))
				render_HorzDoor(game, ray, i, y);
			if (ray[i].foundvertdoor && (y >= 0 && y < HEIGHT))
				render_VertDoor(game, ray, i, y);
			y++;
		}
		i++;
	}
}


void	load_weapon(t_game *game)
{
	int y = HEIGHT + (HEIGHT / 2.4);
	int y2 = HEIGHT + (HEIGHT / 2.4) - 150;
    int x = WIDTH / 2.855;
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
