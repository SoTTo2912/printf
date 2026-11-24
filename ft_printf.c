/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:51:35 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:56:34 by sotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handler(char c, va_list *args)
{
    if (c == 'c')
        return (ft_putchar(va_arg(*args, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(*args, char *)));
    else if (c == 'p')
        return (ft_putptr(va_arg(*args, void *)));
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(*args, int)));
    else if (c == 'u')
        return (ft_putunbr(va_arg(*args, unsigned int)));
    else if (c == 'x' || c == 'X')
        return (ft_puthex(va_arg(*args, unsigned int), c));
    else if (c == '%')
        return (ft_putchar('%'));
    return (-1);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

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
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}
