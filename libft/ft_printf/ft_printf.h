/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:41:41 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:41:45 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include <unistd.h>

int		printf_ft_putchar_fd(char c, int fd);
int		printf_ft_putnbr_fd(int n, int fd, int c);
int		printf_ft_putnbr_hexa(unsigned int nb, char *base, int fd, int c);
int		printf_ft_putstr_fd(char *s, int fd);
int		ft_printf(const char *format, ...);
int		printf_ft_putnbr_fd_u(unsigned int n, int fd, int c);
size_t	printf_ft_strlen(const char *str);
int		printf_ft_putnbr_ptr(unsigned long long ptr, int fd);
int		ft_println(const char *format, ...);
int		ft_printf_err(const char *format, ...);

#endif
