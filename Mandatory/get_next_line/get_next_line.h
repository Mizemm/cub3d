/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:16:11 by asalmi            #+#    #+#             */
/*   Updated: 2025/02/20 23:07:41 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*str_data;
	struct s_list	*next;
}	t_list;

t_list	*found_last_node(t_list *list);
char	*get_next_line(int fd);
char	*get_line(t_list *list);

int		found_newline(t_list *list);
int		get_len_line(t_list *list);

void	copy_string(t_list *list, char *string);
void	free_list(t_list **list, t_list *new_node, char *buf);
void	edit_list(t_list **list);
void	append(t_list **list, char *buf);
void	creat_list(t_list **list, int fd);

#endif