/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:54:50 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 10:46:06 by vicarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(int nb)
{
	int		count;
	long	num;

	num = nb;
	count = 0;
	if (num < 0)
	{
		count += printf_char('-');
		num = -num;
	}
	if (num > 9)
		count += printf_int(num / 10);
	count += printf_char((num % 10) + '0');
	return (count);
}
