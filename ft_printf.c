/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:33 by oandelin          #+#    #+#             */
/*   Updated: 2023/01/23 18:04:38 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	convert_id(int n)
{
	return (ft_putnbr_fd(n, 1));
}

int	convert_c(int c)
{
	return (ft_putchar_fd((char) c, 1));
}

int	convert_u(unsigned int n)
{
	return (ft_putuint_fd(n, 1));
}

int	convert_str(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	else 
		return (ft_putstr_fd(s, 1));
}

int	check_specifier (const char *format, va_list args, int i)
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
	 	return(ft_putchar_fd('%', 1));
	return(0);
}

int parse_format (const char *format, va_list args)
{
	int i;
	int ret;

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
	return(ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	// char	*output;
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
	ret = parse_format(format, args);
	// output = (char *)format;
	// ret = ft_putstr_fd(output, 1);
		
	va_end(args);
	return (ret);
}
