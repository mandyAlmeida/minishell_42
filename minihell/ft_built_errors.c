/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaferre <amaferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:37:01 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:20 by amaferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_change_global_err(int err)
{
	static int	error_code;

	if (err == -1)
		return (error_code);
	error_code = err;
	return (error_code);
}

void	ft_last_errors(t_token *token, t_builins err_type)
{
	if (err_type == no_directory)
		ft_printf_err("Minishell: %s: %s: Not a directory\n",
			token->data, token->next->data);
	else if (err_type == invalid_identifier)
		ft_printf_err("Minishell: export: `%s': not a valid identifier\n",
			token->data);
	if (ft_change_global_err(-1) == 0)
		ft_change_global_err(1);
}

void	ft_more_errors(t_token *tkn, t_builins err_type)
{
	if (err_type == no_file && !ft_strcmp(tkn->data, "cd"))
	{
		ft_printf_err("Minishell: %s: No such file or directory\n", tkn->data);
		ft_change_global_err(127);
	}
	else if (err_type == cmd_not_found)
	{
		ft_printf_err("Minishell: command '%s' not found\n", tkn->data);
		ft_change_global_err(127);
	}
	else if (err_type == alpha_on_num)
	{
		ft_printf_err("Minishell: %s: %s: numeric argument required\n",
			tkn->data, tkn->next->data);
		ft_change_global_err(2);
	}
	else if (err_type == args_err)
		ft_printf_err("Minishell: %s: too many arguments\n", tkn->data);
	else if (err_type == no_file)
		ft_printf_err("Minishell: %s: %s: "
			"No such file or directory\n", tkn->data, tkn->next->data);
	else if (err_type == no_home)
		ft_printf_err("Minishell: %s: HOME not set\n", tkn->data);
	ft_last_errors(tkn, err_type);
}

void	ft_built_err(t_token *token, t_builins err_type)
{
	ft_change_global_err(0);
	if (err_type == flag_err_env || err_type == flag_err)
	{
		ft_printf_err("Minishell: %s : -%c: invalid option\n%s: "
			"usage: has no options in Minishell\n", token->data,
			token->next->data[1], token->data);
		if (err_type == flag_err_env)
			ft_change_global_err(125);
		else
			ft_change_global_err(2);
	}
	else if (err_type == file_permissions && !ft_strcmp(token->data, "cd"))
	{
		ft_printf_err("Minishell: %s: Permission denied\n", token->data);
		ft_change_global_err(126);
	}
	else if (err_type == is_dir)
	{
		ft_printf_err("Minishell: %s: Is a directory\n", token->data);
		ft_change_global_err(126);
	}
	else if (err_type == file_permissions)
		ft_printf_err("Minishell: %s: %s: Permission denied\n",
			token->data, token->next->data);
	ft_more_errors(token, err_type);
}
