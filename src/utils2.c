/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:50:09 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/18 16:32:36 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned trgb_color(int r, int g, int b, int t)
{
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (t > 255)
		t = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (t < 0)
		t = 0;
	 return ((r << 24) | (g << 16) | (b << 8) | t);
}

int depth_color(t_ray ray)
{
	int i;

	i = 0;
	while (i < ray.distance)
		i++;
	if (i > 255)
		i = 255;
	return (i);
}
