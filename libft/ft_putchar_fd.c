/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:21:18 by oandelin          #+#    #+#             */
/*   Updated: 2023/01/17 10:14:12 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_putchar_fd
// writes single char c to file descriptor fd
int	ft_putchar_fd(char c, int fd)
{
	int i;

	i = write(fd, &c, 1);
	return (i);
}
