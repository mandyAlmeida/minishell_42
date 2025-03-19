/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:46:50 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 19:15:03 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			size;
	int long	nb;

	nb = n;
	size = len_nb(nb);
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	if (nb == 0)
		dest[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		dest[0] = '-';
	}
	dest[size] = '\0';
	while (nb > 0)
	{
		dest[size - 1] = (nb % 10) + '0';
		size--;
		nb = nb / 10;
	}
	return (dest);
}
