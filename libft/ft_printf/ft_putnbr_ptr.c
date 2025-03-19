/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:42:43 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:23:18 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_ptr(unsigned long long ptr, int fd)
{
	char	*base;
	int		c;

	c = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
	{
		c = print_ptr(ptr / 16, fd);
		ptr = ptr % 16;
	}
	if (ptr < 16)
		c += printf_ft_putchar_fd(base[ptr], fd);
	return (c);
}

int	printf_ft_putnbr_ptr(unsigned long long ptr, int fd)
{
	int	c;

	c = 0;
	if (!ptr)
	{
		c = printf_ft_putstr_fd("(nil)", 1);
		return (c);
	}
	c = printf_ft_putstr_fd("0x", 1);
	c += print_ptr(ptr, fd);
	return (c);
}
