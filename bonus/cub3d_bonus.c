/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/25 01:41:47 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d_bonus.h"

void	rebuild_game(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	cast_rays(game);
	draw_minimap(game);
}

void	ft_raycasting(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	find_player(game);
	doors_allocted(game);
	cast_rays(game);
	draw_minimap(game);
}

void	setup_mouse(double xpos, double ypos, void *param)
{
	t_game		*game;
	int			x;
	int			y;
	int			dfs;
	const int	center_x;

	(void)xpos;
	(void)ypos;
	game = param;
	center_x = WIDTH / 2;
	x = 0;
	y = 0;
	dfs = 0;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	dfs = x - center_x;
	if (dfs < 0)
		rotate_left(game);
	if (dfs > 0)
		rotate_right(game);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
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
	render_weapon(game);
	ft_raycasting(game);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, setup_mouse, game);
	mlx_loop_hook(game->mlx, &movement_hook, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
