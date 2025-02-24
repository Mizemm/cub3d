/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:49:18 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/24 02:36:45 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	horizontal_intersection(t_game *game, double angle)
{
	double	check_stepx;
	double	check_stepy;

	init_horizontal_intersection(game, angle);
	check_stepx = 0;
	check_stepy = 0;
	while (game->horizontal.next_horz_stepx >= 0
		&& game->horizontal.next_horz_stepx <= game->width * UNIT_SIZE
		&& game->horizontal.next_horz_stepy >= 0
		&& game->horizontal.next_horz_stepy <= game->height * UNIT_SIZE)
	{
		check_stepx = game->horizontal.next_horz_stepx;
		check_stepy = game->horizontal.next_horz_stepy;
		// if (is_facing_up(angle))
		// 	check_stepy -= 1;
		if (is_doors(game, check_stepx, check_stepy))
			game->horizontal.close_horz_door = true;
		check_horz_door(game, check_stepx, check_stepy, angle);
		if (check_horz_wall(game, check_stepx, check_stepy))
			break ;
		game->horizontal.next_horz_stepx += game->horizontal.x_step;
		game->horizontal.next_horz_stepy += game->horizontal.y_step;
	}
}

void	vertical_intersection(t_game *game, double angle)
{
	double	check_stepx;
	double	check_stepy;

	init_vertical_intersection(game, angle);
	check_stepx = 0;
	check_stepy = 0;
	while (game->vertical.next_vert_stepx >= 0
		&& game->vertical.next_vert_stepx <= game->width * UNIT_SIZE
		&& game->vertical.next_vert_stepy >= 0
		&& game->vertical.next_vert_stepy <= game->height * UNIT_SIZE)
	{
		check_stepx = game->vertical.next_vert_stepx;
		check_stepy = game->vertical.next_vert_stepy;
		// if (is_facing_left(angle))
		// 	check_stepx -= 1;
		if (is_doors(game, check_stepx, check_stepy))
			game->vertical.close_vert_door = true;
		check_vert_door(game, check_stepx, check_stepy, angle);
		if (check_vert_wall(game, check_stepx, check_stepy))
			break ;
		game->vertical.next_vert_stepx += game->vertical.x_step;
		game->vertical.next_vert_stepy += game->vertical.y_step;
	}
}

void	find_distance(t_game *game, t_ray *ray, double angle)
{
	double	horizontal_distance;
	double	vertical_distance;

	horizontal_distance = INT_MAX;
	vertical_distance = INT_MAX;
	horizontal_intersection(game, angle);
	vertical_intersection(game, angle);
	if (game->horizontal.found_horz_wall)
		horizontal_distance = calculate_distance(game->player.position_x,
				game->player.position_y, game->horizontal.horz_wall_hitx,
				game->horizontal.horz_wall_hity);
	if (game->vertical.found_vert_wall)
		vertical_distance = calculate_distance(game->player.position_x,
				game->player.position_y, game->vertical.vert_wall_hitx,
				game->vertical.vert_wall_hity);
	if (horizontal_distance < vertical_distance)
		init_horz_rays(game, ray, horizontal_distance);
	else
		init_vert_rays(game, ray, vertical_distance);
	ray->distance *= cos(game->player.angle_rotation - angle);
}

void	cast_rays(t_game *game)
{
	int		i;
	double	angle;

	i = 0;
	angle = game->player.angle_rotation - (FOV / 2);
	game->is_door = false;
	while (i < game->rays_number)
	{
		game->rays[i].found_horz_door = false;
		game->rays[i].found_vert_door = false;
		game->rays[i].open_horz_door = false;
		game->rays[i].open_vert_door = false;
		game->rays[i].found_no = false;
		game->rays[i].found_so = false;
		game->rays[i].found_ea = false;
		game->rays[i].found_we = false;
		game->rays[i].found_horz_door = false;
		game->rays[i].found_vert_door = false;
		game->rays[i].ray_angle = normalize_angle(angle);
		find_distance(game, &game->rays[i], game->rays[i].ray_angle);
		rays_direction(&game->rays[i]);
		angle += (FOV / game->rays_number);
		i++;
	}
	render_textures(game, game->rays);
}
