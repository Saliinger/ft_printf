/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:19:41 by anoukan           #+#    #+#             */
/*   Updated: 2024/09/14 14:19:41 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd_printf(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd_printf(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb >= 0 && nb <= 9)
		ft_putchar_fd_printf(nb + '0', fd);
	else if (nb < 0)
	{
		ft_putchar_fd_printf('-', fd);
		ft_putnbr_fd_printf(nb * -1, fd);
	}
	else
	{
		ft_putnbr_fd_printf(nb / 10, fd);
		ft_putchar_fd_printf(nb % 10 + '0', fd);
	}
}
