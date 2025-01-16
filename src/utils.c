/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:45:21 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/16 14:40:13 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char **get_map(char **map)
{
	map[0]  = strdup("111111111111111111111111");
    map[1]  = strdup("100100000000000000000001");
    map[2]  = strdup("1001000000N0000000000001");
    map[3]  = strdup("100100000000000000000001");
    map[4]  = strdup("111111100100000011100001");
    map[5]  = strdup("100000000011000011101111");
    map[6]  = strdup("111101111111101110000001");
    map[7]  = strdup("111101111111110111011001");
    map[8]  = strdup("110000001101010111000001");
    map[9]  = strdup("100000000000000110000011");
    map[10] = strdup("100000000000000011010111");
    map[11] = strdup("110000011101010111101111");
    map[12] = strdup("111101111110101101111001");
    map[13] = strdup("111111111111111111111111");
    map[14] = NULL;
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

bool is_wall(t_game *game, double x, double y)
{
	if (x < 0 || y < 0 || x >= game->WIDTH * UNIT_SIZE || y >= game->HEIGHT * UNIT_SIZE)
		return (false);
	int x_tmp = floor(x / UNIT_SIZE);
	int y_tmp = floor(y / UNIT_SIZE);
	return (game->map[y_tmp][x_tmp] == '1');
}

double calculate_distance(double x1, double y1, double x2, double y2)
{
	double dx;
	double dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (sqrt((dx * dx) + (dy * dy)));
}
