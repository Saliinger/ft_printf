/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0002/10/20 12:20:50 by noukan            #+#    #+#             */
/*   Updated: 2023/10/31 09:41:20 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (!cdst && !csrc)
		return (cdst);
	if (cdst > csrc)
		while (len--)
			cdst[len] = csrc[len];
	else
	{
		i = -1;
		while (++i < len)
			cdst[i] = csrc[i];
	}
	return (cdst);
}
