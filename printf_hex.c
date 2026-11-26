/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:54:31 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 10:07:53 by vicarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_hex(unsigned long nb, char *base)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += printf_hex(nb / 16, base);
	count += printf_char(base[nb % 16]);
	return (count);
}
