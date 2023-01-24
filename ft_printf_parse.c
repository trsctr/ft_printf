/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:55:55 by oandelin          #+#    #+#             */
/*   Updated: 2023/01/24 15:56:54 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	check_specifier(const char *format, va_list args, int i)
{
	if (format[i] == 'i' || format[i] == 'd')
		return (convert_id(va_arg(args, int)));
	else if (format[i] == 'c')
		return (convert_c(va_arg(args, int)));
	else if (format[i] == 'u')
		return (convert_u(va_arg(args, unsigned int)));
	else if (format[i] == 'x' || format[i] == 'X')
		return (convert_x(va_arg(args, unsigned int), format[i]));
	else if (format[i] == 's')
		return (convert_str(va_arg(args, char *)));
	else if (format[i] == 'p')
		return (convert_p(va_arg(args, void *)));
	else if (format[i] == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int parse_format(const char *format, va_list args)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += check_specifier(format, args, i);
		}
		else
			ret += ft_putchar_fd(format[i], 1);
		i++;
	}
	return (ret);
}