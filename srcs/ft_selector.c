/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:39:55 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 11:06:18 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_convert(char c, va_list *args)
{
	if (c == 'd' || c == 'i')
		return (ft_decimal(va_arg(*args, int)));
	if (c == 's')
		return (ft_string(va_arg(*args, char *)));
	if (c == 'c')
		return (ft_printchar(va_arg(*args, int)));
	if (c == 'u')
		return (ft_uint(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(*args, unsigned int), c));
	if (c == 'p')
		return (ft_pointertohex(va_arg(*args, unsigned long long)));
	if (c == '%')
		return (ft_printchar('%'));
	return (0);
}

void	ft_selector(const char *format, va_list *args, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (!*format)
				break ;
			*count += ft_convert(*format, args);
		}
		else
			*count += ft_printchar(*format);
		++format;
	}
}
