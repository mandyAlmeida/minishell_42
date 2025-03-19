/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:58:56 by estferna          #+#    #+#             */
/*   Updated: 2025/03/19 19:47:16 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_token(t_commands *cur, t_token *token);
static void	ft_get_pipe_nbr(int *n_pipes, t_token *token);

t_commands	*ft_build_commands(t_token *token)
{
	t_commands	*commands;
	int			i;
	int			n_pipes;

	i = -1;
	ft_get_pipe_nbr(&n_pipes, token);
	commands = ft_calloc(n_pipes + 1, sizeof(t_commands));
	while (++i <= n_pipes)
	{
		commands[i].tokens = NULL;
		if (i < n_pipes)
			commands[i].next = &commands[i + 1];
		else
			commands[i].next = NULL;
	}
	i = 0;
	while (token)
	{
		if (token->type == PIPE)
			i++;
		else
			ft_add_token(&commands[i], token);
		token = token->next;
	}
	return (commands);
}

static void	ft_add_token(t_commands *cmd, t_token *token)
{
	t_token	*new_token;
	t_token	*cur;

	new_token = ft_calloc(1, sizeof(t_token));
	new_token->data = ft_strdup(token->data);
	new_token->type = token->type;
	new_token->next = NULL;
	if (!cmd->tokens)
		cmd->tokens = new_token;
	else
	{
		cur = cmd->tokens;
		while (cur->next)
			cur = cur->next;
		cur->next = new_token;
	}
}

static void	ft_get_pipe_nbr(int *n_pipes, t_token *token)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == PIPE)
			i++;
		token = token->next;
	}
	*n_pipes = i;
}
