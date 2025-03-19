/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:48:02 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:56:28 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return ((void *)0);
}
