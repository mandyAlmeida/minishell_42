/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:48:51 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:48:54 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
		char str[8] = "bro";
		char str1[8] = "hello";

		printf("%s\n", str);

		ft_memcpy(str, str1, sizeof(str1));
		//memcpy(str, str1, sizeof(str1));
		printf("%s\n", str);

		return 0;
}
*/
