/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:51:46 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/18 23:05:42 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t count_line(int fd)
{
	int counter;
	char *line;

	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	return (counter);
}

char **get_map(char *file_map)
{
	int fd;
	size_t size;
	
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (NULL);
	}
	size = count_line(fd);
	
}

int main()
{
	mlx_t *mlx;
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->WIDTH = 500;
	game->HEIGHT = 256;
	mlx = mlx_init(game->WIDTH, game->HEIGHT, "cub3d", false);
	if (!mlx)
		return (1);
	get_map("maps/map.txt");
	// mlx_image_t *background = mlx_new_image(mlx, game->WIDTH, game->HEIGHT);
	// mlx_loop(mlx);
	return (0);
}