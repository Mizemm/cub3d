/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:38:35 by mizem             #+#    #+#             */
/*   Updated: 2025/01/20 00:04:40 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int parsing_error(t_game *game)
{
    if (!game->map[0] || !game->elements[0] || borders(game) == 1)
        return (1);
    if (ft_strlen(game->trash))
        return (1);
    return (0);
}