/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:11 by asalmi            #+#    #+#             */
/*   Updated: 2024/06/11 16:05:49 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct s_lst
{
	char			*str_data;
	struct s_lst	*next;
}			t_lst;

t_lst	*found_last_node(t_lst *list);
char	*get_next_line(int fd);
char	*get_line_please(t_lst *list);

int		found_newline(t_lst *list);
int		get_len_line(t_lst *list);

void	copy_string(t_lst *list, char *string);
void	free_list(t_lst **list, t_lst *new_node, char *buf);
void	edit_lst(t_lst **list);
void	append(t_lst **list, char *buf);
void	creat_lst(t_lst **list, int fd);

#endif
