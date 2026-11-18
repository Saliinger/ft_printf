/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0003/10/20 10:54:29 by noukan            #+#    #+#             */
/*   Updated: 2023/10/30 13:20:38 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	length;
	char	*dest;
	size_t	i;
	char	*csrc;

	i = 0;
	csrc = (char *)src;
	length = ft_strlen(csrc);
	dest = (char *)malloc((length + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (csrc[i])
	{
		dest[i] = csrc[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
