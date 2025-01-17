/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:35:42 by mizem             #+#    #+#             */
/*   Updated: 2024/01/06 22:12:07 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] != s1[i])
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i - 1] == set[j])
				break ;
			j++;
		}
		if (s1[i - 1] != set[j])
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*dst;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	if (!s1[i])
		return (ft_strdup(""));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	dst = malloc((end - start + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (start + i < end)
	{
		dst[i] = s1[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
