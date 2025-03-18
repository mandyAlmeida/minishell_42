/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:35 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:52:38 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *str)
{
	int c;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		c++;
	}
	return (c);
}

size_t ft_arraylen(char **str)
{
	int c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}
