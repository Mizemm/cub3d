/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:38:35 by mizem             #+#    #+#             */
/*   Updated: 2025/02/19 18:30:24 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	file_check(char *name)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (name[i])
	{
		if (name[i] == '.')
		{
			count += 1;
            if (name[i + 1] != 'c' || name[i + 2] != 'u' 
                || name[i + 3] != 'b' || name[i + 4] != '\0')
                return (1);
		}
		i++;
	}
	if (count != 1)
        return (1);
	return (0);
}
int flag(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);

}

int empty_lines(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i])
	{
		if (flag(game->map[i]) == 0 && flag(game->map[i + 1]) == 1)
			return (1);
		i++;
	}
	return (0);
}
int parsing_error(t_game *game)
{
    if (!game->map[0] || !game->elements[0] || borders(game) == 1)
        return (1);
    if (ft_strlen(game->trash))
        return (1);
    if (floor_color_check(game) == 1 || floor_color_check_2(game) == 1 || ceiling_color_check(game) == 1 || ceiling_color_check_2(game) == 1)
        return (1);
	if (empty_lines(game) == 1)
		return (1);
    return (0);
}