/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:49 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:52:50 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int c;
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	c = 0;
	while (c < n && (s1[c] || s2[c]))
	{
		if (str1[c] != str2[c])
		{
			return (str1[c] - str2[c]);
		}
		c++;
	}
	return (0);
}
/*
int	main()
{
	unsigned int	n = 5;


	printf("%d", ft_strncmp("vola", "ola jovem", n));
	printf("\n%d", ft_strncmp("Hello", "Ve", n));
	printf("\n%d", ft_strncmp("hello", "hello", n));
}
*/
