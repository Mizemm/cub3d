/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:17:25 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 20:17:59 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

uint32_t	color(uint8_t *arr)
{
	return ((arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | 0xFF);
}

void	render_weapon(t_game *game)
{
	int	y;
	int	y2;
	int	x;

	y = HEIGHT + (HEIGHT / 2.4);
	y2 = HEIGHT + (HEIGHT / 2.4) - 150;
	x = WIDTH / 2.855;
	mlx_image_to_window(game->mlx, game->textures->weapon_img[0], y, x);
	mlx_image_to_window(game->mlx, game->textures->weapon_img[1], y2, x);
	mlx_image_to_window
		(game->mlx, game->textures->crosshair_img[0], WIDTH / 2, HEIGHT / 2);
	game->textures->weapon_img[1]->enabled = false;
}

void	animate_weapon(t_game *game)
{
	game->textures->weapon_img[0]->enabled = false;
	game->textures->weapon_img[1]->enabled = true;
}

void	deanimate_weapon(t_game *game)
{
	game->textures->weapon_img[1]->enabled = false;
	game->textures->weapon_img[0]->enabled = true;
}
