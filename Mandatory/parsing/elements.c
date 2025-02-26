/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:31:53 by mizem             #+#    #+#             */
/*   Updated: 2025/02/26 00:18:22 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	elements_counter(char *line)
{
	char	buffer[1024];
	int		j;
	int		fd;
	int		index;
	int		b_read;

	j = 0;
	fd = open(line, O_RDWR);
	b_read = 1;
	index = 0;
	while (b_read > 0)
	{
		b_read = read(fd, &buffer[index], 1);
		if (b_read > 0 && buffer[index] == '\n')
		{
			j++;
			buffer[index + 1] = '\0';
			if (map_finder(buffer) == 1)
				return (j - 1);
			index = 0;
		}
		else
			index++;
	}
	return (j);
}

void	elements(t_game *game, char *line)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = elements_counter(line);
	fd = open(line, O_RDWR);
	game->elements = malloc(sizeof(char *) * (j + 1));
	while (i < j)
	{
		game->elements[i] = get_next_line(fd);
		if (!game->elements[i] || map_finder(game->elements[i]) == 1)
			break ;
		i++;
	}
	game->elements[i] = NULL;
	close(fd);
}

int	struct_elements(t_game *game)
{
	int		i;
	int		flag;
	int		flag_2;
	char	**str;

	i = 0;
	flag = 0;
	flag_2 = 0;
	if (!*(game->elements))
		return (1);
	while (game->elements[i])
	{
		str = ft_split(game->elements[i], " \t");
		flag = flag_counter(game, str, flag);
		flag_2 = flag_counter_2(game, str, flag_2);
		ft_free(str);
		i++;
	}
	if ((flag + flag_2) != 6)
		return (1);
	return (0);
}
