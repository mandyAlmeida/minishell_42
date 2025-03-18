

#include "../minishell.h"

void	ft_env(t_env *env, t_token *token)
{
	ft_change_global_err(0);
	if (!env)
		return ;
	if (env->content == NULL)
		return ;
	if (token->next != NULL && token->next->type == FLAG)
	{
		ft_built_err(token, flag_err_env);
		return ;
	}
	while (env)
	{
		if (env->content != NULL)
			ft_printf("%s%s%s\n", env->title, "=", env->content);
		if (!env->next)
			return ;
		env = env->next;
	}
}
