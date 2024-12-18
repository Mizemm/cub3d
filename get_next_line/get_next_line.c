/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:19:22 by asalmi            #+#    #+#             */
/*   Updated: 2024/12/18 22:58:49 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	edit_lst(t_lst **list)
{
	t_lst	*new_node;
	t_lst	*last_node;
	char	*buf;
	int		i;
	int		j;

	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_lst));
	if (new_node == NULL || buf == NULL)
		return ;
	last_node = found_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_data[i] && last_node->str_data[i] != '\n')
		i++;
	if (last_node->str_data[i] && last_node->str_data[i] == '\n')
		i++;
	while (last_node->str_data[i])
		buf[j++] = last_node->str_data[i++];
	buf[j] = '\0';
	new_node->str_data = buf;
	new_node->next = NULL;
	free_list(list, new_node, buf);
}

char	*get_line_please(t_lst *list)
{
	char	*str_line;
	int		lenght_line;

	if (list == NULL)
		return (NULL);
	lenght_line = get_len_line(list);
	str_line = malloc(lenght_line + 1);
	if (str_line == NULL)
		return (NULL);
	copy_string(list, str_line);
	return (str_line);
}

void	append(t_lst **list, char *buf)
{
	t_lst	*new_node;
	t_lst	*last_node;

	last_node = found_last_node(*list);
	new_node = malloc(sizeof(t_lst));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_data = buf;
	new_node->next = NULL;
}

void	creat_lst(t_lst **list, int fd)
{
	char	*buf;
	int		num_read;

	while (!found_newline(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		num_read = read(fd, buf, BUFFER_SIZE);
		if (!num_read)
		{
			free(buf);
			return ;
		}
		buf[num_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_lst	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	creat_lst(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line_please(list);
	edit_lst(&list);
	return (next_line);
}
