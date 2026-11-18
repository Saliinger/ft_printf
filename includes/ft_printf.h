/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:42:00 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 08:42:00 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../lib//libft/libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

// Selector
void	ft_selector(const char *format, va_list args, int *count);

// Char/String part
int		ft_printchar(char c);
int		ft_putstr(char *str);
int		ft_string(char *str);

// Decimal part
int		ft_countdigit(long nbr);
int		ft_decimal(int n);

// Unsigned Int
int		ft_uint(int value);
int		ft_countdigit_u(unsigned long nbr);
void	ft_putnbr_u(unsigned long nbr);

// Hex part
int		ft_hex(unsigned int nbr, const char c);
int		ft_hexcount(unsigned int n);
int		ft_pointertohex(unsigned long long ptr);
int		ft_ptrlen(uintptr_t ptr);

#endif
