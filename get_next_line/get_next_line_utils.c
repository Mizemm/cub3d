/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:00:10 by asalmi            #+#    #+#             */
/*   Updated: 2024/05/23 19:23:53 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*found_last_node(t_lst *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	get_len_line(t_lst *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->str_data[i])
		{
			if (list->str_data[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	copy_string(t_lst *list, char *string)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->str_data[i])
		{
			if (list->str_data[i] == '\n')
			{
				string[j++] = '\n';
				string[j] = '\0';
				break ;
			}
			string[j++] = list->str_data[i++];
		}
		list = list->next;
	}
	string[j] = '\0';
}

void	free_list(t_lst **list, t_lst *new_node, char *buf)
{
	t_lst	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_data);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new_node->str_data[0])
		*list = new_node;
	else
	{
		free(buf);
		free(new_node);
	}
}

int	found_newline(t_lst *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_data[i] && i < BUFFER_SIZE)
		{
			if (list->str_data[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

// int main()
// {
//     char *str = malloc(100);
//     t_lst *node1 = malloc(sizeof(t_lst));
//     t_lst *node2 = malloc(sizeof(t_lst));
//     t_lst *node3 = malloc(sizeof(t_lst));

//     node1->str_data = "\n";
//     node2->str_data = "world ";
//     node3->str_data = "1337 ";

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     copy_string(node1, str);
//     printf("%s", str);
// }
