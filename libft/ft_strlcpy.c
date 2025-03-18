/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:31 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:52:32 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int c;

	c = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[c] != '\0' && c < size - 1)
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	return (ft_strlen(src));
}
/*
int	main()
{
	char	src[]="fck arround"; // 11 chars
	char	dest[] = "find out";
	int	n;

	n = sizeof(dest);
	printf("%s\n", src);

	printf("%s\n", dest);
	printf("%d", ft_strlcpy(dest, src, 20));
}
*/
