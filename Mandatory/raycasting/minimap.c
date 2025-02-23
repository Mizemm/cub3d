/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:58:06 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/22 23:45:43 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	minimap_line(t_game *game, double px, double py)
{
	int	i;

	i = -1;
	init_line(game, px, py);
	if (fabs(game->minimap.dx) > fabs(game->minimap.dy))
		game->minimap.steps = fabs(game->minimap.dx);
	else
		game->minimap.steps = fabs(game->minimap.dy);
	game->minimap.x_inc = (game->minimap.dx / (game->minimap.steps));
	game->minimap.y_inc = (game->minimap.dy / (game->minimap.steps));
	while (++i <= game->minimap.steps)
	{
		mlx_put_pixel(game->minimap_img, round(px), round(py), rgbt_color(155,
				77, 214, 255));
		if (bounds_error(game, px, py) == 1)
			break ;
		px += game->minimap.x_inc;
		py += game->minimap.y_inc;
	}
}

void	minimap_player(t_game *game)
{
	double	px;
	double	py;
	int		i;
	int		j;

	px = game->minimap_width / 2;
	py = game->minimap_height / 2;
	i = -3;
	while (i < 3)
	{
		j = -3;
		while (j < 3)
		{
			mlx_put_pixel(game->minimap_img, px + j, py + i, rgbt_color(155, 77,
					214, 255));
			j++;
		}
		i++;
	}
	minimap_line(game, px, py);
}

int	check_for_draw(t_game *game, int x, int y)
{
	double	px;
	double	py;
	int		xd;
	int		yd;

	px = game->minimap_width / 2;
	py = game->minimap_height / 2;
	xd = (x - px) / ZOOM;
	yd = (y - py) / ZOOM;
	xd = (game->player.position_x) + xd;
	yd = (game->player.position_y) + yd;
	if (xd < 0 || yd < 0 || yd >= game->height * UNIT_SIZE)
		return (-1);
	xd /= UNIT_SIZE;
	yd /= UNIT_SIZE;
	if (game->map[yd][xd] == '\n' || game->map[yd][xd] == '\t'
		|| xd >= ft_strlen(game->map[yd]))
		return (-1);
	if (game->map[yd][xd] == '1' || game->map[yd][xd] == 32)
		return (1);
	if (game->map[yd][xd] == 'C')
		return (2);
	if (game->map[yd][xd] == 'O')
		return (3);
	return (0);
}

void	darw_object(t_game *game)
{
	int	x;
	int	y;
	int	status;

	y = 0;
	while (y < game->minimap_height)
	{
		x = 0;
		while (x < game->minimap_width)
		{
			status = check_for_draw(game, x, y);
			start_draw(game, x, y, status);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_game *game)
{
	darw_object(game);
	minimap_player(game);
}
