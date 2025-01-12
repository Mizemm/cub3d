/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amine <Amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/01/10 20:39:19 by Amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void rebuild_game(t_game *game)
{
	mlx_delete_image(game->mlx, game->background_img);
	mlx_delete_image(game->mlx, game->player.player_image);
	mlx_delete_image(game->mlx, game->wall_img);
	draw_background(game);
	draw_wall(game);
	draw_player(game);
	cast_rays(game);
	draw_line(game);
}

void ft_raycasting(t_game *game)
{
	draw_background(game);
	draw_wall(game);
	draw_player(game);
	cast_rays(game);
	draw_line(game);
}

int main()
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_struct(game);
	// printf("angle: %f\n", game->player.angle_rotation);
	ft_raycasting(game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
