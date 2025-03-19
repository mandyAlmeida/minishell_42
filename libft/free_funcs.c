/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:45:19 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 19:08:04 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_args(char **numbers)
{
	int	i;

	i = 0;
	if (!numbers || !*numbers)
		return ;
	while (numbers[i] != NULL)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
