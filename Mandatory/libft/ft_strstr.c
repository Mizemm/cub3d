/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:08:52 by mizem             #+#    #+#             */
/*   Updated: 2025/01/20 14:09:07 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_strstr(char *src, char *dst, int i)
{
	int	j;

	if (dst[i] == '\0')
		return (1);
	while (src[i])
	{
		j = 0;
		while (dst[j] == src[i + j] && dst[j])
			j++;
		if (!dst[j] && ft_strlen(dst) == j)
			return (0);
		i++;
	}
	return (1);
}