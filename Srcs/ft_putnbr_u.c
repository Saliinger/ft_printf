/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:39:37 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 08:39:38 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned long nbr)
{
	if (nbr <= 9)
		ft_printchar(nbr + '0');
	else
	{
		ft_putnbr_u(nbr / 10);
		ft_printchar(nbr % 10 + '0');
	}
}
