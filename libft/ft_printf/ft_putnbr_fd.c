/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:42:28 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:22:17 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putnbr_fd(int n, int fd, int c)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		c = 11;
	}
	else
	{
		if (n < 0)
		{
			c += printf_ft_putchar_fd('-', fd);
			n = -n;
		}
		while (n > 9)
		{
			c = printf_ft_putnbr_fd(n / 10, fd, c);
			n = n % 10;
		}
		if (n < 10)
			c += printf_ft_putchar_fd(n + 48, fd);
	}
	return (c);
}
