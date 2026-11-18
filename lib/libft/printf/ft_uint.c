/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:58:15 by anoukan           #+#    #+#             */
/*   Updated: 2023/11/14 10:52:40 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint(int value)
{
	unsigned int	unsigned_value;

	if (value < 0)
		unsigned_value = (unsigned int)value + 4294967296;
	else
		unsigned_value = (unsigned int)value;
	ft_putnbr_u(unsigned_value);
	return (ft_countdigit_u(unsigned_value));
}
