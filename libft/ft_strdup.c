/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:07 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 19:09:42 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		c;
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dest)
		return (0);
	c = 0;
	while (src[c])
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}

char	*ft_fine_strdup(char const *src, int start, int end)
{
	int		c;
	char	*dest;

	dest = (char *)ft_calloc((end - start) + 2, sizeof(char));
	if (!dest)
		return (0);
	c = 0;
	while (start <= end)
	{
		dest[c] = src[start];
		start++;
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
