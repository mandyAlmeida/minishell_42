/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:23 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:52:26 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t c;
	size_t c2;
	size_t i;

	c = 0;
	c2 = 0;
	while (dest[c] && c < size)
	{
		c++;
		c2++;
	}
	if (c2 == size)
		return (c2 + ft_strlen(src));
	i = 0;
	while (src[i])
	{
		if (i < size - 1 - c2)
		{
			dest[c] = src[i];
			c++;
		}
		i++;
	}
	dest[c] = '\0';
	return (c2 + i);
}
