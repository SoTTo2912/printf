/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:55:32 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:56:34 by sotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_str(char *str)
{
    int	count;

    count = 0;
    if (!str)
        str = "(null)";
    while (*str)
    {
        count += printf_char(*str);
        str++;
    }
    return (count);
}
