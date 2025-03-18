/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:53:02 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:53:03 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			ptr = (char *)str;
		str++;
	}
	if ((char)c == 0)
		return ((char *)str);
	return (ptr);
}
/*
int	main()
{
	char	*ptr;
	char	tweet[] = "ola hfrihehnd";

	ptr = ft_strrchr(tweet, 'h');

	printf("%s", ptr);
}
*/
