/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:37:51 by anoukan           #+#    #+#             */
/*   Updated: 2023/10/30 13:21:17 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t l)

{
	size_t	i;

	i = 0;
	if (!dest || !str || l == 0)
		return (ft_strlen(str));
	while (str[i] && i < (l - 1))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(str));
}
