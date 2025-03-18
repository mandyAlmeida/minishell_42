

#include "../minishell.h"

char	*ft_get_env(t_env *env, char *str)
{
	while (env->next != NULL)
	{
		if (!env->title)
			break ;
		if (ft_strcmp(str, env->title) != 1)
			env = env->next;
		else
			break ;
	}
	if (env->title && ft_strcmp(str, env->title) == 1)
		return (env->content);
	if (env->next && ft_strcmp(str, env->next->title))
		return (env->next->title);
	return (NULL);
}

char	*ft_path(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	return (buffer);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (result);
}

void	ft_make_temp(t_commands *cmd, t_commands *temp, t_token *tokens)
{
	t_token	*new;
	t_token	*current;

	tokens = cmd->tokens;
	if (!tokens)
	{
		temp->tokens = NULL;
		return ;
	}
	temp->tokens = malloc(sizeof(t_token));
	temp->tokens->data = ft_strdup(tokens->data);
	temp->tokens->type = tokens->type;
	temp->tokens->next = NULL;
	current = temp->tokens;
	tokens = tokens->next;
	while (tokens)
	{
		new = malloc(sizeof(t_token));
		new->data = ft_strdup(tokens->data);
		new->type = tokens->type;
		new->next = NULL;
		current->next = new;
		current = new;
		tokens = tokens->next;
	}
}

t_env	*ft_create_new(char *tit, char *cont)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->title = ft_strdup(tit);
	if (cont != NULL)
		new_node->content = ft_strdup(cont);
	else
		new_node->content = NULL;
	new_node->next = NULL;
	return (new_node);
}
