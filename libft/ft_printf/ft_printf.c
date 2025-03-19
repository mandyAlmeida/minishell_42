/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:41:31 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:22:47 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(int fd, char type, va_list args)
{
	if (type == 'c')
		return (printf_ft_putchar_fd(va_arg(args, int), fd));
	else if (type == 's')
		return (printf_ft_putstr_fd(va_arg(args, char *), fd));
	else if (type == 'd' || type == 'i')
		return (printf_ft_putnbr_fd(va_arg(args, int), fd, 0));
	else if (type == 'x')
		return (printf_ft_putnbr_hexa(va_arg(args, int),
				"0123456789abcdef", fd, 0));
	else if (type == 'X')
		return (printf_ft_putnbr_hexa(va_arg(args, int),
				"0123456789ABCDEF", fd, 0));
	else if (type == 'p')
		return (printf_ft_putnbr_ptr(va_arg(args, unsigned long long), fd));
	else if (type == 'u')
		return (printf_ft_putnbr_fd_u(va_arg(args, int), fd, 0));
	else if (type == '%')
		return (printf_ft_putchar_fd('%', fd));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		fd;

	fd = 1;
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += print_format(fd, *(++format), args);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_printf_err(const char *format, ...)
{
	va_list	args;
	int		len;
	int		fd;

	fd = 2;
	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += print_format(fd, *(++format), args);
		else
			len += write(2, format, 1);
		format++;
	}
	va_end(args);
	return (len);
}

int	ft_println(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += print_format(1, *(++format), args);
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(args);
	write(2, "\n", 1);
	return (len);
}
