/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/19 20:37:59 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include/cub3d.h"

void rebuild_game(t_game *game)
{
	// mlx_delete_image(game->mlx, game->image);
	// mlx_delete_image(game->mlx, game->minimap_img);
	draw_ceiling(game);
	draw_floor(game);
	// draw_wall(game);
	// draw_doors(game);
	// draw_player(game);
	cast_rays(game);
	render_weapon(game);
	draw_minimap(game);
}

void ft_raycasting(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	find_player(game);
	// draw_wall(game);
	// draw_doors(game);
	// draw_player(game);
	doors_allocted(game);
	cast_rays(game);
	draw_minimap(game);
}

// void setup_mouse(t_game *game)
// {
// 	mlx_cursor_hook(game->mlx, mouse_hook, game);
// }
void leaks(void)
{
	system("leaks cub3d");
}
int main(int ac, char **av)
{	
	t_game *game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	// atexit(leaks);
	init_struct(game);
	parsing(game, av[1]);
	load_textures(game);
	ft_raycasting(game);
	// setup_mouse(game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	// mlx_delete_image(game->mlx, game->image);
	// mlx_delete_image(game->mlx, game->minimap_img);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
