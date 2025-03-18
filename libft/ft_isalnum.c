/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:45:42 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:45:45 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalnum(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))
		return (1);
	return (0);
}
/*
int main()
{
	int	output;
	char str[] = "123";
	char err[] = "ola 2 peps";
	output = ft_str_is_numeric( str);
	printf("%d\n%d", output ,ft_str_is_numeric( err));



}
*/
