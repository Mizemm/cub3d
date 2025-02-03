/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:50:09 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/03 00:41:43 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

unsigned rgbt_color(int r, int g, int b, int t)
{
	return ((r << 24) | (g << 16) | (b << 8) | t);
}

int depth_color(double distance, int terp)
{
	(void)terp;
    double brightness = 200 - (distance * 0.7);
    if (brightness > 150)
        brightness = 150;
	if (brightness < 50)
		brightness = 50;
    return (int)brightness;
}

// void mouse_hook(void *param)
// {
// 	int mouse_x;
// 	int mouse_y;
// }