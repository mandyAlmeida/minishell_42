/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:37:19 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:53 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_update_pwd(t_env *env, char *path)
{
	char	*pwd;

	if (env->content == NULL)
		return (NULL);
	pwd = ft_strdup(env->content);
	free(env->content);
	env->content = ft_strdup(path);
	free(path);
	return (pwd);
}

char	*ft_get_new_old(t_env *env)
{
	char	*pwd;
	char	*path;

	path = ft_path();
	pwd = NULL;
	while (env->next)
	{
		if (ft_strcmp(env->title, "PWD"))
		{
			pwd = ft_update_pwd(env, path);
			return (pwd);
		}
		env = env->next;
	}
	if (ft_strcmp(env->title, "PWD"))
	{
		pwd = env->content;
		env->content = ft_strdup(path);
	}
	else
		env->next = ft_create_new("PWD", path);
	free(path);
	return (pwd);
}

void	ft_change_pwd(t_env *env)
{
	char	*old_pwd;

	old_pwd = ft_get_new_old(env);
	while (env->next)
	{
		if (ft_strcmp(env->title, "OLDPWD"))
		{
			free(env->content);
			if (old_pwd != NULL)
				env->content = ft_strdup(old_pwd);
			else
				env->content = NULL;
			free(old_pwd);
			return ;
		}
		env = env->next;
	}
	if (ft_strcmp(env->title, "OLDPWD"))
		env->content = ft_strdup(old_pwd);
	if (!ft_strcmp(env->title, "OLDPWD") && old_pwd != NULL)
		env->next = ft_create_new("OLDPWD", old_pwd);
	free(old_pwd);
}

int	ft_can_change(t_token *token)
{
	struct stat	path;

	if (token->next && access(token->next->data, F_OK) == 0)
	{
		if (stat(token->next->data, &path) == 0 && S_ISDIR(path.st_mode))
		{
			if (access(token->next->data, R_OK) == 0)
				return (1);
			else
				ft_built_err(token, file_permissions);
		}
		else
			ft_built_err(token, no_directory);
	}
	else
		ft_built_err(token, no_file);
	return (0);
}

void	ft_cd(t_token *token, t_env **env)
{
	ft_change_global_err(0);
	if (token->next == NULL)
	{
		if (ft_get_env(*env, "HOME") != NULL)
		{
			chdir(ft_get_env(*env, "HOME"));
			ft_change_pwd(*env);
		}
		else
			ft_built_err(token, no_home);
	}
	else if (token->next && token->next->type == FLAG)
		ft_built_err(token, flag_err);
	else if (token->next && token->next->next)
		ft_built_err(token, args_err);
	else if (ft_can_change(token))
	{
		chdir(token->next->data);
		ft_change_pwd(*env);
	}
}
