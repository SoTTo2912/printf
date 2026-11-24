/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:54:50 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:56:34 by sotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(int nb)
{
    int	count;

    count = 0;
    if (nb < 0)
    {
        count += printf_char('-');
        nb = -nb;
    }
    if (nb > 9)
        count += printf_int(nb / 10);
    count += printf_char((nb % 10) + '0');
    return (count);
}
