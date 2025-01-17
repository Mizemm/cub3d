/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:31:53 by mizem             #+#    #+#             */
/*   Updated: 2025/01/15 20:21:33 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	elements_counter(char *map_name)
{
	char	*ptr;
    char    buffer[1024];
	int		i;
	int		j;
	int		fd;
	int		index;
    int     b_read;

	i = 0;
	fd = open("map.cub", O_RDWR);
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
    int i;
	int j;
	int fd;

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
void	struct_elements(t_game *game)
{
	int i;
	char **str;

	i = 0;
	if (!*(game->elements))
		return ;
	while (game->elements[i])
	{
		str = ft_split(game->elements[i], " 	");
		if (ft_strcmp(str[0], "NO") == 0)
			game->NO_DATA = ft_strdup(str[1]);
		else if (ft_strcmp(str[0], "SO") == 0)
			game->SO_DATA = ft_strdup(str[1]);
		else if (ft_strcmp(str[0], "WE") == 0)
			game->WE_DATA = ft_strdup(str[1]);
		else if (ft_strcmp(str[0], "EA") == 0)
			game->EA_DATA = ft_strdup(str[1]);
		else if (ft_strcmp(str[0], "F") == 0)
			game->FLOOR_DATA = ft_strdup(str[1]);
		else if (ft_strcmp(str[0], "C") == 0)
			game->CEILING_DATA = ft_strdup(str[1]);
		i++;
		ft_free(str);
	}
}