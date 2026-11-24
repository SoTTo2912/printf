/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:53:32 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:56:34 by sotto            ###   ########.fr       */
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