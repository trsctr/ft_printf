/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:33 by oandelin          #+#    #+#             */
/*   Updated: 2023/01/20 19:44:20 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
int check_specifier (en tiia mita taa ottaa sisaan)
{
	if (format[i+1] == 'i')
		return (convert_int(va_arg(args, int)));
	else if (format[i+1] == 'c')
		return (convert_char(va_arg(args, int)));
	else if (format[i+1] == 'd')
		ret += convert decimal
	else if (format[i+1] == 'u')
		ret += convert unsigned_decimal
	else if (format[i+1] == 'x')
		ret += convert hex
	else if (format[i+1] == 'X')
		ret += convert hex_capital
	else if (format[i+1] == 's')
		return (convert_str(va_arg(args, const char *)));
	else if (format[i+1] == 'p')
		ret += convert pointer
	else if (format[i+1] == '%')
		ret += convert persent

}
*/
/*
int parse_format (const char *format, va_list args)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ret += check_specifier
		else
			ret += ft_putchar_fd(format[i], 1);
		i++;
	}

}

*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*output;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(args, format);
	// scan *format for specifiers
	// need to recognize the specifiers and link them to correct args
	// are the args strings?
	// format is a string. figure out how to replace %s with a string.
	// 
	output = (char *)format;
	ret = ft_putstr_fd(output, 1);
		
	va_end(args);
	return (ret);
}
