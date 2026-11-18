/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:39:04 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 10:34:55 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnb(unsigned int nb, const char c)
{
	if (nb >= 16)
	{
		ft_putnb(nb / 16, c);
		ft_putnb(nb % 16, c);
	}
	else
	{
		if (nb <= 9)
			ft_printchar(nb + '0');
		else
		{
			if (c == 'x')
				ft_printchar(nb - 10 + 'a');
			if (c == 'X')
				ft_printchar(nb - 10 + 'A');
		}
	}
}

int	ft_hex(unsigned int nb, const char c)
{
	if (nb == 0)
		return (ft_printchar('0'));
	else
		ft_putnb(nb, c);
	return (ft_hexcount(nb));
}
