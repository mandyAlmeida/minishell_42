/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:42:36 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:42:38 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int printf_ft_putnbr_hexa(unsigned int nb, char *base, int fd, int c)
{
	unsigned int len;

	len = printf_ft_strlen(base);
	if (nb >= len)
	{
		c = printf_ft_putnbr_hexa(nb / len, base, fd, c);
		nb = nb % len;
	}
	if (nb < len)
		c += printf_ft_putchar_fd(base[nb], fd);
	return (c);
}
