/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:50:09 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/15 20:37:31 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

unsigned int rgbt_color(int r, int g, int b, int t)
{
	return ((r << 24) | (g << 16) | (b << 8) | t);
}

// int depth_color(double distance, int terp)
// {
// 	(void)terp;
//     double brightness = 200 - (distance * 0.7);
//     if (brightness > 150)
//         brightness = 150;
// 	if (brightness < 50)
// 		brightness = 50;
//     return (int)brightness;
// }

void mouse_hook(double xpos, double ypos, void *param)
{
    static int prev_posx = -1;
    t_game *game;

    game = (t_game *)param;
    mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);

    if (prev_posx == -1)
    {
        prev_posx = xpos;
    }
    else
    {
        double sensitivity = 0.01;
        double delta = (xpos - prev_posx) * sensitivity;
        game->player.angle_rotation += delta;
        game->player.angle_rotation = normalize_angle(game->player.angle_rotation);
        prev_posx = xpos;
    }
    mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
    rebuild_game(game);
}

void rays_direction(t_ray *ray)
{
	double angle = ray->ray_angle;
	if (is_facing_up(angle) && ray->foundHorz)
		ray->foundNO = true;
	if (is_facing_down(angle) && ray->foundHorz)
		ray->foundSO = true;
	if (is_facing_right(angle) && ray->foundVert)
		ray->foundEA = true;
	if (is_facing_left(angle) && ray->foundVert)
		ray->foundWE = true;
}
