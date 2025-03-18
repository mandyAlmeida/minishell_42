/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:45:08 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 14:45:11 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_error_exit(char *str)
{
	int len;

	len = ft_strlen(str);
	write(STDERR_FILENO, str, len);
	exit(EXIT_FAILURE);
}
