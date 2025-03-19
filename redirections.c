/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:43:56 by estferna          #+#    #+#             */
/*   Updated: 2025/03/19 19:57:30 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_do_redirect(t_token *token);

int	ft_handle_redirects(t_token *token)
{
	while (token)
	{
		if (token->type == R_IN || token->type == R_OUT \
			|| token->type == R_OUT2)
		{
			if (ft_do_redirect(token) == FAILURE)
				return (FAILURE);
			token = token->next;
		}
		token = token->next;
	}
	return (SUCCESS);
}

int	ft_redirect_out(t_token *token)
{
	int	fd;

	if (token->type == R_OUT2)
		fd = open(token->next->data, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(token->next->data, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd > 0)
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (fd);
}

int	ft_redirect_in(t_token *token)
{
	int	fd;

	fd = open(token->next->data, O_RDONLY);
	if (fd > 0)
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (fd);
}

int	ft_do_redirect(t_token *token)
{
	int	fd;

	fd = -1;
	if (token->type == R_OUT || token->type == R_OUT2)
		fd = ft_redirect_out(token);
	else if (token->type == R_IN)
		fd = ft_redirect_in(token);
	if (fd == -1)
	{
		if (ft_heredoc_sig(-1) != FAILURE)
		{
			ft_change_global_err(1);
			ft_printf_err("no such file or directory\n");
		}
		return (FAILURE);
	}
	return (SUCCESS);
}

t_token	*ft_token_dup(t_token *token)
{
	int		size;
	int		i;
	t_token	*dup;
	t_token	*head;

	size = ft_token_counter_until_redd(token);
	if (size == 0)
		return (NULL);
	i = 0;
	dup = ft_calloc(size, sizeof(t_token));
	head = dup;
	while (i < size && token)
	{
		dup->data = ft_strdup(token->data);
		dup->type = token->type;
		if (i < size - 1)
			dup->next = dup + 1;
		else
			dup->next = NULL;
		token = token->next;
		dup = dup->next;
		i++;
	}
	return (head);
}
