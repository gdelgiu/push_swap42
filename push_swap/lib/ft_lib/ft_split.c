/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:38:40 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/01/22 15:11:33 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static unsigned int	count_words(char *str, char div)
{
	unsigned int	i;
	unsigned int	count;
	short int		toggle;

	i = 0;
	count = 0;
	toggle = 0;
	while (str[i])
	{
		if (str[i] != div && toggle == 0)
		{
			count++;
			toggle = 1;
		}
		if (str[i] == div)
			toggle = 0;
		i++;
	}
	return (count);
}

char	**create_list(char **list, char *s, char c)
{	
	unsigned int	scan;
	unsigned int	i;
	unsigned int	list_index;

	i = 0;
	scan = 0;
	list_index = 0;
	while (s[scan])
	{
		if (s[scan] != c)
		{
			while (s[scan + i] && s[scan + i] != c)
				i++;
			list[list_index] = ft_substr(s, scan, i);
			list_index++;
			scan += i;
			i = 0;
		}
		else
			scan++;
	}
	list[list_index] = NULL;
	return (list);
}

char	**ft_split(char *str, char c)
{
	char	**splitted;

	if (!str)
		return (NULL);
	splitted = (char **) malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	return (create_list(splitted, str, c));
}
