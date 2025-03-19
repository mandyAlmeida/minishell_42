/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:48:23 by amaferre          #+#    #+#             */
/*   Updated: 2025/03/19 17:01:27 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip(char **str, char i)
{
	(*str)++;
	while ((**str) || (**str) != '\0')
	{
		if ((**str) == i)
		{
			(*str)++;
			return ;
		}
		(*str)++;
	}
	return ;
}

int	words_quotes(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			ft_skip(&s, *s);
			count++;
		}
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	insert(char **split, char *s, char c)
{
	char	*temp;

	temp = s;
	while (*temp)
	{
		while (*s == c)
			s++;
		temp = s;
		while (*temp != c && *temp)
		{
			if (*temp == '\'' || *temp == '\"')
				ft_skip(&temp, *temp);
			else
				temp++;
		}
		if (*temp == c || temp > s)
		{
			*split = ft_substr(s, 0, temp - s);
			s = temp;
			split++;
		}
	}
	*split = NULL;
}

char	**ft_quotes_split(char *s, char c)
{
	char	**split;
	int		size;

	size = words_quotes(s, c);
	if (!s)
		return (NULL);
	split = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (!split)
		return (NULL);
	insert(split, s, c);
	return (split);
}
