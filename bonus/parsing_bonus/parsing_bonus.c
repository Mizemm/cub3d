/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/25 23:29:56 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	parsing(t_game *game, char *line)
{
	if (file_check(line) == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	elements(game, line);
	map(game, line);
	game->width = count_width(game->map);
	game->height = count_height(game->map);
	if (struct_elements(game) == 1 || parsing_error(game) == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
