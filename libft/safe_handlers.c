/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:54:36 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:54:39 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_safe_malloc(int size)
{
	char *mem;

	mem = malloc(size);
	if (!mem)
		ft_error_exit("malloc error");
	return (mem);
}

void *ft_safe_calloc(size_t space, size_t type)
{
	char *mem;

	mem = ft_calloc(space, type);
	if (!mem)
		ft_error_exit("calloc error");
	return (mem);
}
