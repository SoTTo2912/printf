/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:53:32 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 09:52:48 by vicarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_dec(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += printf_dec(nb / 10);
	count += printf_char((nb % 10) + '0');
	return (count);
}
