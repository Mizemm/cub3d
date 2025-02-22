/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:20:10 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 02:03:14 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	floor_color_check(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (game->floor_color[i])
	{
		if (game->floor_color[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		return (1);
	return (0);
}

int	mini_color_check(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		if (ft_atoi(ptr[i]) < 0 || ft_atoi(ptr[i]) > 255 
			|| ft_strlen(ptr[i]) > 3)
			return (1);
		while (ptr[i][j])
		{
			if (ft_isdigit(ptr[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	floor_color_check_2(t_game *game)
{
	int		i;
	int		j;
	int		flag;
	char	**ptr;

	i = 0;
	flag = 0;
	ptr = ft_split(game->floor_color, ",\n");
	if (mini_color_check(ptr) == 1)
		return (1);
	game->floor_color_int[0] = ft_atoi(ptr[0]);
	game->floor_color_int[1] = ft_atoi(ptr[1]);
	game->floor_color_int[2] = ft_atoi(ptr[2]);
	game->floor_color_int[3] = 255;
	ft_free(ptr);
	return (0);
}

int	ceiling_color_check(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (game->ceiling_color[i])
	{
		if (game->ceiling_color[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		return (1);
	return (0);
}

int	ceiling_color_check_2(t_game *game)
{
	int		i;
	int		j;
	int		flag;
	char	**ptr;

	i = 0;
	flag = 0;
	ptr = ft_split(game->ceiling_color, ",\n");
	if (mini_color_check(ptr) == 1)
		return (1);
	game->ceiling_color_int[0] = ft_atoi(ptr[0]);
	game->ceiling_color_int[1] = ft_atoi(ptr[1]);
	game->ceiling_color_int[2] = ft_atoi(ptr[2]);
	game->ceiling_color_int[3] = 255;
	ft_free(ptr);
	return (0);
}
