/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/16 01:34:13 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include/cub3d.h"

void rebuild_game(void *param)
{
	t_game *game;
	// printf("Rebuilding game...\n");
	game = (t_game *)param;
	if (game->minimap_img)
		mlx_delete_image(game->mlx, game->minimap_img);
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	draw_ceiling(game);
	draw_floor(game);
	// draw_wall(game);
	// draw_doors(game);
	// draw_player(game);
	doors_allocted(game);
	draw_minimap(game);
	cast_rays(game);
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
	draw_minimap(game);
	cast_rays(game);
}

// void setup_mouse(t_game *game)
// {
// 	mlx_cursor_hook(game->mlx, mouse_hook, game);
// }


int main(int ac, char **av)
{	
	t_game *game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_struct(game);
	parsing(game, av[1]);
	load_textures(game);
	ft_raycasting(game);
	// setup_mouse(game);
	// mlx_loop_hook(game->mlx, &rebuild_game, game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	// mlx_key_hook(game->mlx, movement_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
