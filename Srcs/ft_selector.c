/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoukan <alnoukan@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 08:39:55 by alnoukan          #+#    #+#             */
/*   Updated: 2026/11/18 08:39:56 by alnoukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_selector(const char *format, va_list args, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'd' || *format == 'i')
				*count += ft_decimal(va_arg(args, int));
			else if (*format == 's')
				*count += ft_string(va_arg(args, char *));
			else if (*format == 'c')
				*count += ft_printchar(va_arg(args, int));
			else if (*format == 'u')
				*count += ft_uint(va_arg(args, int));
			else if (*format == 'X' || *format == 'x')
				*count += ft_hex(va_arg(args, unsigned int), *format);
			else if (*format == 'p')
				*count += ft_pointertohex(va_arg(args, unsigned long long));
			else if (*format == '%')
				*count += ft_printchar('%');
		}
		else
			*count += ft_printchar(*format);
		++format;
	}
}
