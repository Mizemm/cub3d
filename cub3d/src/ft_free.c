/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:36:14 by mizem             #+#    #+#             */
/*   Updated: 2025/01/14 19:22:51 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	delete_texture(t_map *var)
// {
// 	if (var->walls_texture)
// 		mlx_delete_texture(var->walls_texture);
// 	if (var->player_texture)
// 		mlx_delete_texture(var->player_texture);
// 	if (var->exit_texture)
// 		mlx_delete_texture(var->exit_texture);
// 	if (var->background_texture)
// 		mlx_delete_texture(var->background_texture);
// 	if (var->banana_texture)
// 		mlx_delete_texture(var->banana_texture);
// }

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}