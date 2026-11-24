/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:55:05 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:58:21 by sotto            ###   ########.fr       */
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
