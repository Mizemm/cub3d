/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:38:35 by mizem             #+#    #+#             */
/*   Updated: 2025/01/17 21:14:42 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int elements_error(t_game *game)
{
    int i;
    int flag;


    i = 0;
    flag = 0;
    printf("NO_DATA = %s\n", game->NO_DATA);
    if (ft_strcmp(game->NO_DATA, "NO") == 0)
        flag++;
    // printf("flag = %d\n", flag);
    // while(1)
    // {
    //     if (ft_strcmp(game->NO_DATA, "NO") == 0 || ft_strcmp(game->SO_DATA, "SO") == 0 || ft_strcmp(game->WE_DATA, "WE") == 0 
    //     || ft_strcmp(game->EA_DATA, "EA") == 0 || ft_strcmp(game->FLOOR_DATA, "F") == 0 || ft_strcmp(game->CEILING_DATA, "C") == 0)
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
    if (elements_error(game) == 1 || game->trash[0])
        return (1);
    return (0);
}