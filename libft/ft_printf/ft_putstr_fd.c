/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:42:52 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:21:06 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_ft_putstr_fd(char *s, int fd)
{
	int	c;

	if (!s)
		s = "(null)";
	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
	return (c);
}
