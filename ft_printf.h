/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicarauj <vicarauj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 09:42:55 by vicarauj          #+#    #+#             */
/*   Updated: 2026/11/25 10:08:43 by vicarauj         ###   ########.fr       */
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
