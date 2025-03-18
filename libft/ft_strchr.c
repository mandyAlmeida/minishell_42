/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:50:26 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:50:28 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (NULL);
}

int ft_strchr_bool(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (0);
		str++;
	}
	return (1);
}
/*
int	main()
{
	char	*ptr;
	char	tweet[] = "ola friend";

	ptr = ft_strchr(tweet, 'f');

	printf("%s", ptr);
}
*/
