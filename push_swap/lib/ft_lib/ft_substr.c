/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 08:28:35 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/01/22 15:10:25 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_substr(char *s, int start, int len)
{
	char    *str;
	int     i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) > start && len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start && len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *) ft_calloc(len + 1, sizeof(char));
	if (!*s || start > ft_strlen(s) || len > ft_strlen(s) - start)
		return (str);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
