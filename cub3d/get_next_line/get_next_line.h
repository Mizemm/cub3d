/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:59:17 by mizem             #+#    #+#             */
/*   Updated: 2025/01/14 22:36:13 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		ft_counter(char *s);
char	*ft_read(int fd, char *res);
char	*find_line(char *str);
char	*update_str(char *old_str);
int     ft_strlen(char *s);
void	*ft_calloc(int count, int size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		find_new_line(char *s);

#endif