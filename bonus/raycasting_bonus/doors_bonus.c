/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:41:12 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/25 01:39:56 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	open_door(t_game *game)
{
	int		midd_index;
	int		grid_x;
	int		grid_y;
	double	distance;
	t_ray	*midd_ray;

	midd_index = game->rays_number / 2;
	midd_ray = &game->rays[midd_index];
	distance = calculate_distance(game->player.position_x,
			game->player.position_y, midd_ray->wall_hitx, midd_ray->wall_hity);
	grid_x = (int)(midd_ray->wall_hitx / UNIT_SIZE);
	grid_y = (int)(midd_ray->wall_hity / UNIT_SIZE);
	if ((midd_ray->found_vert_door || midd_ray->found_horz_door)
		&& distance <= 65)
		check_for_open(game, grid_x, grid_y);
}

void	close_vert(t_game *game, t_ray *midd_ray)
{
	int	i;

	i = 0;
	if (midd_ray->open_vert_door && check_for_close(game, midd_ray->v_openx,
			midd_ray->v_openy))
	{
		while (i < doors_counter(game))
		{
			if (game->doors[i].x == midd_ray->v_openx
				&& game->doors[i].y == midd_ray->v_openy)
			{
				game->map[midd_ray->v_openy][midd_ray->v_openx] = 'C';
				game->doors[i].is_closed = true;
			}
			i++;
		}
	}
}

void	close_horz(t_game *game, t_ray *midd_ray)
{
	int	i;

	i = 0;
	if (midd_ray->open_horz_door && check_for_close(game, midd_ray->h_openx,
			midd_ray->h_openy))
	{
		while (i < doors_counter(game))
		{
			if (game->doors[i].x == midd_ray->h_openx
				&& game->doors[i].y == midd_ray->h_openy)
			{
				game->map[midd_ray->h_openy][midd_ray->h_openx] = 'C';
				game->doors[i].is_closed = true;
				break ;
			}
			i++;
		}
	}
}

void	close_door(t_game *game)
{
	int		i;
	int		midd_index;
	t_ray	*midd_ray;

	i = 0;
	midd_index = game->rays_number / 2;
	midd_ray = &game->rays[midd_index];
	find_distance(game, midd_ray, game->player.angle_rotation);
	close_vert(game, midd_ray);
	close_horz(game, midd_ray);
}
