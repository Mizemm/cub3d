/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:45:21 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/31 11:14:48 by asalmi           ###   ########.fr       */
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
size_t get_height(char **map)
{
	int size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

size_t get_width(char **map)
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

double normalize_angle(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}
