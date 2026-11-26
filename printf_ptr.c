/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:55:05 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 09:52:44 by vicarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (printf_str("(nil)"));
	count = 0;
	count += printf_str("0x");
	count += printf_hex((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
