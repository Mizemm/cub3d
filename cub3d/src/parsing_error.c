/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:38:35 by mizem             #+#    #+#             */
/*   Updated: 2025/01/19 19:57:34 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int elements_error(t_game *game)
{
    int i;
    int flag;


    i = 0;
    flag = 0;
    if (ft_strcmp(game->no_path, "NO") == 0)
        flag++;
    // while(1)
    // {
    //     if (ft_strcmp(game->no_path, "NO") == 0 || ft_strcmp(game->so_path, "SO") == 0 || ft_strcmp(game->we_path, "WE") == 0 
    //     || ft_strcmp(game->ea_path, "EA") == 0 || ft_strcmp(game->floor_color, "F") == 0 || ft_strcmp(game->ceiling_color, "C") == 0)
    //         flag++;
    //     i++;
    //     if (flag != 6)
    //         return (1);
    // }
    return (0);
}
int parsing_error(t_game *game)
{
    if (!game->map[0] || !game->elements[0] || borders(game) == 1)
        return (1);
    if (ft_strlen(game->trash))
        return (1);
    return (0);
}