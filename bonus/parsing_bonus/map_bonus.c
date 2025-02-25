/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:38:03 by mizem             #+#    #+#             */
/*   Updated: 2025/02/22 19:23:53 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int	map_finder(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == '1' || str[i + j] == ' ' 
			|| str[i + j] == '\t')
			j++;
		if (j >= 4)
			return (1);
		i++;
	}
	return (0);
}

void	fill_map(char **str, int fd, int b_read, int index)
{
	char	buffer[1024];
	int		i;

	i = 0;
	while (b_read > 0)
	{
		b_read = read(fd, &buffer[index], 1);
		if (b_read > 0 && buffer[index] == '\n')
		{
			buffer[index + 1] = '\0';
			str[i] = ft_strdup(buffer);
			i++;
			index = 0;
		}
		else
			index++;
	}
	if (index > 0)
	{
		buffer[index - 1] = '\0';
		str[i] = ft_strdup(buffer);
		i++;
	}
	str[i] = NULL;
}

int	map_counter(char *line, char **str)
{
	int		count;
	int		fd;
	int		i;
	int		b_read;
	int		index;

	count = 0;
	fd = open(line, O_RDWR);
	i = 0;
	b_read = 1;
	index = 0;
	fill_map(str, fd, b_read, index);
	while (str[i] && map_finder(str[i]) == 0)
		i++;
	while (str[i])
	{
		count++;
		i++;
	}
	close (fd);
	return (count);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	map(t_game *game, char *line)
{
	int		i;
	int		j;
	int		fd;
	char	*str[1024];

	i = 0;
	j = map_counter(line, str);
	fd = open(line, O_RDONLY);
	game->map = malloc(sizeof(char *) * (j + 1));
	while (str[i] && map_finder(str[i]) == 0)
		i++;
	j = 0;
	while (1)
	{
		if (!str[i])
			break ;
		game->map[j] = ft_strdup(str[i]);
		i++;
		j++;
	}
	game->map[j] = NULL;
	free_str(str);
}
