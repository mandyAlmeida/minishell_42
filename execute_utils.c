/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:09:34 by estferna          #+#    #+#             */
/*   Updated: 2025/03/19 15:45:49 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_expand_cmd(t_commands **cmd, t_env *env)
{
	t_commands *copy_cmd;

	copy_cmd = (*cmd);
	while (copy_cmd)
	{
		ft_find_expand(&copy_cmd->tokens, env);
		copy_cmd = copy_cmd->next;
	}
}

void ft_prep_cmd_struct(t_commands **cmd, t_token *token, t_env *env)
{
	*cmd = ft_build_commands(token);
	free_tokens(token);
	ft_build_heredoc(cmd, *cmd, env);
	ft_expand_cmd(cmd, env);
}

void ft_exec_n_cleanup(t_commands *cmd, t_env *env)
{
	ft_send_to_execve(cmd->tokens, env);
	ft_free_cmd(cmd);
	ft_free_env(env);
}
