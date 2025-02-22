/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/22 01:15:41 by asalmi           ###   ########.fr       */
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

void setup_mouse(double xpos, double ypos, void *param)
{
	t_game *game = param;
	int x = 0;
	int y = 0;
	int dfs = 0;
	const int center_x = WIDTH / 2;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	dfs = x - center_x;
	if (dfs < 0)
		rotate_left(game);
	if (dfs > 0)
		rotate_right(game);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

void set_player_direction(t_game *game)
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
	atexit(leaks);
	init_struct(game);
	parsing(game, av[1]);
	set_player_direction(game);
	load_textures(game);
	ft_raycasting(game);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, setup_mouse, game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	// mlx_delete_image(game->mlx, game->image);
	// mlx_delete_image(game->mlx, game->minimap_img);
	mlx_loop(game->mlx);
	// free_all(game);
	return (0);
}
