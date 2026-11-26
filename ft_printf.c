/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:43:00 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 15:54:34 by vicarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handler(char c, va_list *args)
{
	if (c == 'c')
		return (printf_char(va_arg(*args, int)));
	else if (c == 's')
		return (printf_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (printf_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (printf_int(va_arg(*args, int)));
	else if (c == 'u')
		return (printf_dec(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (printf_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (printf_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (printf_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handler(format[i], &args);
		}
		else
			count += printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
