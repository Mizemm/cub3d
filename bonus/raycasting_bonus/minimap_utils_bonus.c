/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:38:38 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 20:48:52 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	bounds_error(t_game *game, double px, double py)
{
	if (px < 0 || py < 0 || px >= game->minimap_width
		|| py >= game->minimap_width)
		return (1);
	return (0);
}

void	init_line(t_game *game, int px, int py)
{
	game->minimap.x1 = px + (12 * cos(game->player.angle_rotation));
	game->minimap.y1 = py + (12 * sin(game->player.angle_rotation));
	game->minimap.dx = game->minimap.x1 - px;
	game->minimap.dy = game->minimap.y1 - py;
}

int	get_status_color(int status)
{
	if (status == 1)
		return (rgbt_color(27, 27, 27, 255));
	if (status == -1)
		return (rgbt_color(67, 67, 67, 255));
	if (status == 2)
		return (rgbt_color(107, 229, 184, 255));
	if (status == 3)
		return (rgbt_color(204, 204, 255, 255));
	return (rgbt_color(255, 255, 255, 255));
}

void	start_draw(t_game *game, int x, int y, int status)
{
	int	color;

	color = get_status_color(status);
	mlx_put_pixel(game->minimap_img, x, y, color);
}
