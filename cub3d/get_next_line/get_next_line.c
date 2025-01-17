/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:10:47 by mizem             #+#    #+#             */
/*   Updated: 2025/01/14 22:32:23 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_counter(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_read(int fd, char *res)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		res = ft_strjoin(res, buffer);
		if (find_new_line(res) != -1)
			break ;
	}
	free(buffer);
	return (res);
}

char	*find_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!*str)
		return (NULL);
	i = ft_counter(str);
	j = 0;
	if (str[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	return (line);
}

char	*update_str(char *old_str)
{
	int		i;
	int		j;
	char	*new_str;

	if (!old_str)
		return (NULL);
	j = 0;
	i = ft_counter(old_str);
	new_str = ft_calloc(ft_strlen(old_str) - i + 1, sizeof(char));
	if (old_str[i] == '\n')
		i++;
	while (old_str[i + j])
	{
		new_str[j] = old_str[i + j];
		j++;
	}
	free(old_str);
	if (!ft_strlen(new_str))
	{
		free(new_str);
		new_str = (NULL);
	}
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0 || BUFFER_SIZE > INT_MAX 
		|| read(fd, 0, 0) == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = find_line(str);
	str = update_str(str);
	return (line);
}
