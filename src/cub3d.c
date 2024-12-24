/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/24 20:05:37 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **get_map(char **map)
{
	map[0] = strdup("111111111111111111111111111");
	map[1] = strdup("100000000111000000000001101");
	map[2] = strdup("100000000110000000000000001");
	map[3] = strdup("111111100000000011111000001");
	map[4] = strdup("10000000000N000000000000001");
	map[5] = strdup("100000000100001100100000101");
	map[6] = strdup("100000000000000000000000001");
	map[7] = strdup("111111111111000000000001001");
	map[8] = strdup("100000000000001111111000001");
	map[9] = strdup("111111111111111111111111111");
	map[10] = NULL;
	return (map);
}
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

void draw_line(t_game *game)
{
	double x_ep;
	double y_ep;
	double x_tmp;
	double y_tmp;
	int i;
	double dx;
	double dy;
	double steps;
	double x_inc;
	double y_inc;

	i = -1;
	x_ep = game->player.position_x + (30 * cos(game->player.angl_rotation));
	y_ep = game->player.position_y + (30 * sin(game->player.angl_rotation));
	dx = x_ep - game->player.position_x;
	dy = y_ep - game->player.position_y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	x_tmp = game->player.position_x + 5;
	y_tmp = game->player.position_y + 5;
	while (++i <= steps)
	{
		mlx_put_pixel(game->wall_img, round(x_tmp), round(y_tmp), 0xFF0000ff);
		x_tmp += x_inc;
		y_tmp += y_inc;
	}
}

void draw_background(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	game->background_img = mlx_new_image(game->mlx, game->WIDTH * 30, game->HEIGHT * 30);
	if ((!game->background_img) || (mlx_image_to_window(game->mlx, game->background_img, 0, 0) < 0))
		return ;
	while (game->HEIGHT * 30 > y)
	{
		x = 0;
		while (game->WIDTH * 30 > x)
		{
			mlx_put_pixel(game->background_img, x, y, 0xFFFFFFFF);
			x++;	
		}
		y++;
	}
}

void draw_wall(t_game *game)
{
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
	game->wall_img = mlx_new_image(game->mlx, game->WIDTH * 30, game->HEIGHT * 30);
	if ((!game->wall_img) || (mlx_image_to_window(game->mlx, game->wall_img, 0, 0) < 0))
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
						mlx_put_pixel(game->wall_img, x + position_x, y + position_y, 0x000000FF);
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

void draw_player(t_game *game)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	game->player.player_image = mlx_new_image(game->mlx, 10, 10);
	if (!game->player.player_image)
		return ;
	if (mlx_image_to_window(game->mlx, game->player.player_image, game->player.position_x, game->player.position_y) < 0)
		return ;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			mlx_put_pixel(game->player.player_image, x, y, 0xFF0000ff);
			x++;
		}
		y++;
	}
}

void re_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->background_img);
	mlx_delete_image(game->mlx, game->player.player_image);
	mlx_delete_image(game->mlx, game->wall_img);
	draw_background(game);
	draw_wall(game);
	draw_player(game);
	draw_line(game);
}

void ft_raycasting(t_game *game)
{
	draw_background(game);
	draw_wall(game);
	draw_player(game);
	draw_line(game);
}

int main()
{
	mlx_t *mlx;
	t_game *game;
	size_t width;
	size_t height;
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->map = malloc(sizeof(char *) * (10 + 1));
	if (!game->map)
		return (1);
	game->map = get_map(game->map);
	width = count_width(game->map);
	height = count_height(game->map);
	game->WIDTH = width;
	game->HEIGHT = height;
	game->player.rotate_direction = 0;
	game->player.move_direction = 0;
	game->player.rotate_speed = 5 * (M_PI / 180);
	game->player.angl_rotation = M_PI / 2;
	mlx = mlx_init(game->WIDTH * 30, game->HEIGHT * 30, "cub3d", false);
	game->mlx = mlx;
	if (!mlx)
		return (1);
	init_struct(game);
	ft_raycasting(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
