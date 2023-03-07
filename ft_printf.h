/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:56:24 by oandelin          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:56 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	check_specifier(const char *format, va_list args, int i);
int	parse_format(const char *format, va_list args);
int	printhex(unsigned long n, char c);
int	convert_x(unsigned int n, char c);
int	convert_p(void *p);
int	convert_id(int n);
int	convert_u(unsigned int n);
int	convert_c(int c);
int	convert_str(char *s);

#endif