/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizem <mizem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:13:08 by mizem             #+#    #+#             */
/*   Updated: 2024/01/06 22:11:37 by mizem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	s1len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	i = 0;
	dst = malloc((s1len + ft_strlen(s2) + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (i < s1len)
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		dst[s1len + i] = s2[i];
		i++;
	}
	dst[s1len + i] = '\0';
	return (dst);
}
