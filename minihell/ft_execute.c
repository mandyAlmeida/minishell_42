/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:58:14 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/18 19:04:39 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	ft_find_heredoc(t_token *token)
{
	while (token)
	{
		if (token->type == R_IN2)
			return (SUCCESS);
		token = token->next;
	}
	return (FAILURE);
}

void	ft_update_err_code(int status)
{
	if (WIFSIGNALED(status))
	{
		if (status > 128)
			ft_change_global_err(status);
		else
			ft_change_global_err(status + 128);
	}
	else
		ft_change_global_err(WEXITSTATUS(status));
}

void	ft_execute_in(t_token *token, t_env **env, int status)
{
	t_commands	*cmd;
	int			forked;

	forked = 1;
	ft_prep_cmd_struct(&cmd, token, *env);
	if (cmd->next)
		ft_pipe_it(cmd, env);
	else if (ft_handle_redirects(cmd->tokens) != FAILURE
		&& ft_built_in(cmd, env) != SUCCESS)
	{
		set_inner_shell_signals();
		forked = fork();
		while (wait(&status) > 0)
			;
		ft_update_err_code(status);
	}
	if (forked == 0)
	{
		ft_change_global_err(0);
		ft_exec_n_cleanup(cmd, *env);
		exit(ft_change_global_err(-1));
	}
	ft_heredoc_sig(-2);
	ft_free_cmd(cmd);
}

// experimentar negar o strcomp na linha 75
char	*ft_path_to_executable(char **paths, char *command, int using_it)
{
	DIR				*dir;
	struct dirent	*entry;

	while (paths[using_it] != NULL)
	{
		if (access(paths[using_it], F_OK) == 0)
		{
			if (paths[using_it] == NULL)
				return (NULL);
			dir = opendir(paths[using_it]);
			if (dir == NULL)
				return (NULL);
			entry = readdir(dir);
			while (entry != NULL)
			{
				if (ft_strcmp(entry->d_name, command) == SUCCESS)
					return (ft_strdup(paths[using_it]));
				entry = readdir(dir);
			}
			closedir(dir);
		}
		using_it++;
	}
	return (NULL);
}

// At line 112 i know i didnt find the program in 
//the PATHS of the env so i use pwd
char	*ft_right_path(t_token *token, t_env *env, int iswear)
{
	char	**paths;
	char	*found;
	char	*apended;

	paths = NULL;
	if (ft_get_env(env, "PATH") != NULL)
	{
		paths = ft_split(ft_get_env(env, "PATH"), ':');
		found = ft_path_to_executable(paths, token->data, iswear);
	}
	else if (access(token->data, R_OK))
		found = ft_path();
	else
		return (token->data);
	if (!ft_strnstr(token->data, "./", ft_strlen(token->data)))
	{
		found = ft_strjoin_free(found, "/");
		apended = ft_strjoin(found, token->data);
	}
	else
		apended = ft_strdup(token->data);
	if (found)
		free(found);
	free_args(paths);
	return (apended);
}
