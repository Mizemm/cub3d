/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/15 20:49:01 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t count_height(char **map)
{
	int size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

size_t count_width(char **map)
{
	int size_w;
	int size_h;

	size_h = 0;
	while (map[size_h])
	{
		size_w = 0;
		while (map[size_h][size_w])
			size_w++;
		size_h++;
	}
	return (size_w);
}
void draw_background(t_game *game, mlx_t *mlx)
{
	int x;
	int y;
	mlx_image_t *background;

	x = 0;
	y = 0;
	background = mlx_new_image(mlx, game->WIDTH * 30, game->HEIGHT * 30);
	if ((!background) || (mlx_image_to_window(mlx, background, 0, 0) < 0))
		return ;
	while (game->HEIGHT * 30 > y)
	{
		x = 0;
		while (game->WIDTH * 30 > x)
		{
			mlx_put_pixel(background, x, y, 0xFFFFFFFF);
			x++;	
		}
		y++;
	}
}

void draw_wall(t_game *game, mlx_t *mlx)
{
	mlx_image_t *wall_img;
	int x;
	int y;
	int i;
	int j;
	int position_x;
	int position_y;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	position_x = 0;
	position_y = 0;
	wall_img = mlx_new_image(mlx, game->WIDTH * 30, game->HEIGHT * 30);
	if ((!wall_img) || (mlx_image_to_window(mlx, wall_img, 0, 0) < 0))
		return ;
	while (game->map[i])
	{
		j = 0;
		position_x = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				y = 0;
				while (30 > y)
				{
					x = 0;
					while (30 > x)
					{
						mlx_put_pixel(wall_img, x + position_x, y + position_y, 0x000000FF);
						x++;
					}
					y++;
				}
			}
			j++;
		position_x += 30;	
		}
		i++;
		position_y += 30;
	}
}

void draw_player(t_game *game, mlx_t *mlx)
{
	int i;
	int j;
	int x;
	int y;
	mlx_image_t *player_img;
	
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	player_img = mlx_new_image(mlx, 10, 10);
	if (!player_img)
		return ;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N')
			{
				game->player.position_x = j;
				game->player.position_y = i;
				if (mlx_image_to_window(mlx, player_img, j * 30 + 10, i * 30 + 10) < 0)
					return ;
				while (y < 10)
				{
					x = 0;
					while (x < 10)
					{
						mlx_put_pixel(player_img, x, y, 0xFF0000ff);
						x++;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}
}
void init(t_game *game)
{
	game->WIDTH = 0;
	game->HEIGHT = 0;
	game->elements = NULL;
	game->map = NULL;
	game->NO_DATA = NULL;
	game->SO_DATA = NULL;
	game->WE_DATA = NULL;
	game->EA_DATA = NULL;
	game->FLOOR_DATA = NULL;
	game->CEILING_DATA = NULL;
	game->map = malloc(sizeof(char *) * (10 + 1));
	if (!game->map)
		return ;
	game->player.position_x = 0;
	game->player.position_y = 0;
	game->player.angl_rotation = 0;
}

void parsing(t_game *game, char *line)
{
	elements(game, line);
	map(game, line);
	game->WIDTH = count_width(game->map);
	game->HEIGHT = count_height(game->map);
	struct_elements(game);
	printf("%d\n", borders(game));
}
int main(int ac, char **av)
{
	mlx_t *mlx;
	t_game *game;
	if (ac != 2)
		return 1;
	game = malloc(sizeof(t_game));
	if (!game)
		return 1;
	init(game);
	parsing(game, av[1]);
	// game->player.angl_rotation = M_PI / 2;
	// mlx = mlx_init(game->WIDTH * 30, game->HEIGHT * 30, "cub3d", false);
	// if (!mlx)
	// 	return (1);
	// draw_background(game, mlx);
	// draw_wall(game, mlx);
	// draw_player(game, mlx);
	// // draw_line(game);
	// mlx_loop(mlx);
	return (0);
}
