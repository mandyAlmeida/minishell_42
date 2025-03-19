/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:45:37 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 19:10:17 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*mem;
	int		t;

	t = n * size;
	mem = malloc(t);
	if (!mem)
		return (NULL);
	ft_bzero(mem, t);
	return (mem);
}
