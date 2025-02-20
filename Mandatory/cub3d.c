/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/20 01:53:09 by asalmi           ###   ########.fr       */
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

void setup_mouse(void *param)
{
	t_game *game = param;
	int new_x;
	int new_y;
	
	new_x = 0;
	new_y = 0;
	mlx_get_mouse_pos(game->mlx, &new_x, &new_y);
	
}
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
	mlx_loop_hook(game->mlx, &setup_mouse, game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	// mlx_delete_image(game->mlx, game->image);
	// mlx_delete_image(game->mlx, game->minimap_img);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
