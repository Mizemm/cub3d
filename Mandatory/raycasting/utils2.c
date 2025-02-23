/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:50:09 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/23 02:36:06 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned int	rgbt_color(int r, int g, int b, int t)
{
	return ((r << 24) | (g << 16) | (b << 8) | t);
}

void	mouse_hook(double xpos, double ypos, void *param)
{
	static int	prev_posx = -1;
	t_game		*game;
	double		sensitivity;
	double		delta;

	game = (t_game *)param;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	if (prev_posx == -1)
	{
		prev_posx = xpos;
	}
	else
	{
		sensitivity = 0.01;
		delta = (xpos - prev_posx) * sensitivity;
		game->player.angle_rotation += delta;
		game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
		prev_posx = xpos;
	}
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	rebuild_game(game);
}

void	rays_direction(t_ray *ray)
{
	double	angle;

	angle = ray->ray_angle;
	if (is_facing_up(angle) && ray->foundHorz)
		ray->foundNO = true;
	if (is_facing_down(angle) && ray->foundHorz)
		ray->foundSO = true;
	if (is_facing_right(angle) && ray->foundVert)
		ray->foundEA = true;
	if (is_facing_left(angle) && ray->foundVert)
		ray->foundWE = true;
}

size_t	count_height(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

size_t	count_width(char **map)
{
	int	size_w;
	int	size_h;
	int	b_size;

	size_h = 0;
	b_size = 0;
	while (map[size_h])
	{
		size_w = 0;
		while (map[size_h][size_w])
			size_w++;
		if (b_size < size_w)
			b_size = size_w;
		size_h++;
	}
	return (b_size);
}
