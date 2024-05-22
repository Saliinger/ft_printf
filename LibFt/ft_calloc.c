/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0003/10/20 17:26:08 by noukan            #+#    #+#             */
/*   Updated: 2023/11/01 14:48:48 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*i;

	if (count * size > INT_MAX || count > INT_MAX || size > INT_MAX)
		return (NULL);
	i = malloc(count * size);
	if (i)
		ft_bzero(i, count * size);
	return (i);
}
