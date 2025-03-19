/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:53:52 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 16:49:49 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_nl(void *ptr, size_t n)
{
	size_t	i;
	unsigned char *p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

int	str_len(const char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	*ft_calloc_nl(size_t n, size_t size)
{
	void	*mem;
	int	t;

	t = n * size;
	mem = malloc(t);
	if (!mem)
		return (NULL);
	ft_bzero_nl(mem, t);
	return (mem);
}

char *str_join(char *stack, char *buffer)

{
	char *join;
	size_t c;
	size_t i;

	if (!stack || !buffer)
		return (NULL);
	join = ft_calloc_nl(sizeof(char), (str_len(stack) + str_len(buffer) + 1));
	if (!join)
		return (NULL);
	c = 0;
	i = 0;
	while (stack[c])
	{
		join[c] = stack[c];
		c++;
	}
	while (buffer[i])
	{
		join[c] = buffer[i];
		c++;
		i++;
	}
	join[c] = '\0';
	free(stack);
	return (join);
}
