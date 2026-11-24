/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotto <sotto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 22:52:24 by sotto             #+#    #+#             */
/*   Updated: 2026/11/24 22:56:34 by sotto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printf_char(int c);
int	printf_dec(unsigned int nb);
int	printf_hex(unsigned long nb, char *base);
int	printf_int(int nb);
int	printf_ptr(void *ptr);
int	printf_str(char *str);

#endif