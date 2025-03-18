

#include "minishell.h"

int ft_validation_input(char *input)
{
	if (ft_syntax_pipes(input) != SUCCESS)
		return (FAILURE);
	if (ft_syntax_redirects(input) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
