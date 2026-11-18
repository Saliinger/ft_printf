/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frees1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:09:47 by anoukan           #+#    #+#             */
/*   Updated: 2024/12/11 16:09:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_frees1(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	if (s1)
		i = ft_strlen(s1);
	else
		i = 0;
	j = ft_strlen(s2);
	dest = (char *)malloc(i + j + 1);
	if (dest == NULL)
		return (free(s1), s1 = NULL, free(s2), s2 = NULL, NULL);
	if (s1)
		ft_strcpy(dest, (char *)s1);
	ft_strcpy(dest + i, (char *)s2);
	if (s1)
		free(s1);
	return (dest);
}
