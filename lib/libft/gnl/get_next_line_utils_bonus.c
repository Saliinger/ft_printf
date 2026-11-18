/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:05:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/15 18:37:28 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl_gnl(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy_gnl(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*d;
	size_t	f;
	size_t	g;

	d = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	f = 0;
	g = 0;
	if (!d)
		return (free(s1), NULL);
	while (s1[f])
	{
		d[f] = s1[f];
		++f;
	}
	while (s2[g])
	{
		d[f] = s2[g];
		++f;
		++g;
	}
	d[f] = '\0';
	free(s1);
	return (d);
}

int	ft_verify(char *stash)
{
	size_t	i;
	size_t	v;

	v = 0;
	i = ft_strlen_gnl(stash);
	while (stash[v] != '\n' && i != 0)
	{
		i--;
		v++;
	}
	if (stash[i] == '\n' || stash[i] == '\0')
		return (1);
	return (0);
}
