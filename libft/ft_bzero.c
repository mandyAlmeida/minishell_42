/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:45:30 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:45:32 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *ptr, size_t n)
{
	size_t i;
	unsigned char *p;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*

int main()
{
		char str[40] = "GeeksForGeeks is for programming geeks.";

		printf("%s\n", str);
		ft_bzero(str+10, 8);
		printf("%s", str);

		return 0;
}
*/
