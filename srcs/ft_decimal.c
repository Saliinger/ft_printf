/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:38:57 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 10:34:55 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_countdigit(n));
}
