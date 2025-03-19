/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:53:28 by estferna          #+#    #+#             */
/*   Updated: 2025/03/19 16:08:34 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_validation_input(char *input)
{
	if (ft_syntax_pipes(input) != SUCCESS)
		return (FAILURE);
	if (ft_syntax_redirects(input) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
