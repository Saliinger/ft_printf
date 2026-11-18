/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeurhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:39:12 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 10:43:45 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

int	ft_pointertohex(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		ft_printptr(ptr);
		i += ft_ptrlen(ptr);
	}
	return (i);
}
