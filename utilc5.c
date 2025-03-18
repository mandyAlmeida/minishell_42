

#include "minishell.h"

bool ft_see_spe_char(char c)
{
	if ((c > 33 && c <= 39) || (c >= 42 && c <= 47) || (c >= 58 && c <= 59))
		return (SUCCESS);
	return (FAILURE);
}
