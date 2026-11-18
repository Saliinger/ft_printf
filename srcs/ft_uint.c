/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:40:10 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 10:34:55 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
