/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/26 00:33:03 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	rebuild_game(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	cast_rays(game);
}

void	ft_raycasting(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	find_player(game);
	cast_rays(game);
}

void	set_player_direction(t_game *game)
{
	if (game->player_direction == 'N')
		game->player.angle_rotation = (3 * M_PI) / 2;
	else if (game->player_direction == 'S')
		game->player.angle_rotation = M_PI / 2;
	else if (game->player_direction == 'E')
		game->player.angle_rotation = 2 * M_PI;
	else if (game->player_direction == 'W')
		game->player.angle_rotation = M_PI;
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_struct(game);
	parsing(game, av[1]);
	set_player_direction(game);
	load_textures(game);
	ft_raycasting(game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
