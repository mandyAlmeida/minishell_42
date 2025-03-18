/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:46:43 by estferna          #+#    #+#             */
/*   Updated: 2025/03/18 18:46:46 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minishell.h"

static int ft_syntax_1place(char *input, int *c)
{
	while (input[*c] == ' ' || input[*c] == '\t')
		(*c)++;
	if (input[*c] == '|')
		return (FAILURE);
	if (input[*c] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int ft_skip_quotes(char *input, int *c, char i)
{
	(*c)++;
	while (input[*c] || input[*c] != '\0')
	{
		if (input[*c] == i)
			return (SUCCESS);
		(*c)++;
	}
	return (FAILURE);
}

int ft_syntax_pipes(char *input)
{
	int c;

	c = 0;
	if (ft_syntax_1place(input, &c) != SUCCESS)
		return (FAILURE);
	else
	{
		while (input[c])
		{
			if (input[c] == '"' || input[c] == '\'')
				if (ft_skip_quotes(input, &c, input[c]) != SUCCESS)
					return (FAILURE);
			if (input[c] == '|')
			{
				if (input[c + 1] == '|' || input[c + 1] == '\0')
					return (FAILURE);
				c++;
				return (ft_syntax_pipes(input + c));
			}
			c++;
		}
	}
	return (SUCCESS);
}

static int ft_redirect_type(char *input)
{
	bool left;
	bool right;
	int c;

	left = false;
	right = false;
	c = 0;
	if (ft_check_triples(input) != SUCCESS)
		return (FAILURE);
	while (c < 2)
	{
		if (input[c] == '<')
			left = true;
		if (input[c] == '>')
			right = true;
		if (input[c] != '>' && input[c] != '<')
			break;
		c++;
	}
	if (left && right)
		return (FAILURE);
	return (SUCCESS);
}

int ft_syntax_redirects(char *input)
{
	int c;

	c = 0;
	if (ft_syntax_1place(input, &c) != SUCCESS)
		return (FAILURE);
	else
	{
		while (input[c])
		{
			if (input[c] == '"' || input[c] == '\'')
				if (ft_skip_quotes(input, &c, input[c]) != SUCCESS)
					return (FAILURE);
			if (input[c] == '>' || input[c] == '<')
			{
				if (ft_redirect_type(input + c) != SUCCESS)
					return (FAILURE);
				c++;
				if (input[c] == '|' || ft_space_redirect(input + c) != SUCCESS)
					return (FAILURE);
				return (ft_syntax_redirects(input + c));
			}
			c++;
		}
	}
	return (SUCCESS);
}
