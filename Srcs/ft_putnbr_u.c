/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:56:29 by anoukan           #+#    #+#             */
/*   Updated: 2023/11/14 10:53:20 by anoukan          ###   ########.fr       */
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
