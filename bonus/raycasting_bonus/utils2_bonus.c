/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:50:09 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/25 01:39:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

unsigned int	rgbt_color(int r, int g, int b, int t)
{
	return ((r << 24) | (g << 16) | (b << 8) | t);
}

void	rays_direction(t_ray *ray)
{
	double	angle;

	angle = ray->ray_angle;
	if (is_facing_up(angle) && ray->found_horz)
		ray->found_no = true;
	if (is_facing_down(angle) && ray->found_horz)
		ray->found_so = true;
	if (is_facing_right(angle) && ray->found_vert)
		ray->found_ea = true;
	if (is_facing_left(angle) && ray->found_vert)
		ray->found_we = true;
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
