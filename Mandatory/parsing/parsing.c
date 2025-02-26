/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/26 00:26:15 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_nss(t_game *game)
{
	if (game->elements)
		ft_free(game->elements);
	if (game->map)
		ft_free(game->map);
	if (game->no_path)
		free(game->no_path);
	if (game->so_path)
		free(game->so_path);
	if (game->we_path)
		free(game->we_path);
	if (game->ea_path)
		free(game->ea_path);
	if (game->floor_color)
		free(game->floor_color);
	if (game->ceiling_color)
		free(game->ceiling_color);
	if (game->trash)
		free(game->trash);
	free(game);
}

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
		leaks();
		exit(1);
	}
}
