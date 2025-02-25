/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_counters_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:17:35 by mizem             #+#    #+#             */
/*   Updated: 2025/02/24 20:50:39 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	flag_counter(t_game *game, char **str, int flag)
{
	if (ft_strcmp(str[0], "NO") == 0)
	{
		game->no_path = ft_strtrim(str[1], "\n");
		flag++;
	}
	else if (ft_strcmp(str[0], "SO") == 0)
	{
		game->so_path = ft_strtrim(str[1], "\n");
		flag++;
	}
	else if (ft_strcmp(str[0], "WE") == 0)
	{
		game->we_path = ft_strtrim(str[1], "\n");
		flag++;
	}
	else if (ft_strcmp(str[0], "EA") == 0)
	{
		game->ea_path = ft_strtrim(str[1], "\n");
		flag++;
	}
	else if (str && (str[0][0] >= 33 && str[0][0] <= 126) 
	&& ft_strcmp(str[0], "F") != 0 && ft_strcmp(str[0], "C") != 0)
		game->trash = ft_strdup(str[0]);
	return (flag);
}

int	flag_counter_2(t_game *game, char **str, int flag_2)
{
	if (ft_strcmp(str[0], "F") == 0)
	{
		game->floor_color = ft_strtrim(str[1], "\n");
		flag_2++;
	}
	else if (ft_strcmp(str[0], "C") == 0)
	{
		game->ceiling_color = ft_strtrim(str[1], "\n");
		flag_2++;
	}
	return (flag_2);
}
