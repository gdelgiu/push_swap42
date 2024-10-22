/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:42:12 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/02/09 02:34:30 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_commons.h"

static t_size check_terminator(t_int64 longword, const char *str) 
{
	const char *cp;
	t_size i;

	cp = (char *) &longword;
	i = 0;
	while (i < sizeof(longword))
	{
		if (!cp[i])
			return ((t_size)(cp - str + i));
		i++;
	}
	return (0);
}


static t_size fast_strlen(t_int64 *i_ptr, const char *str)
{
	t_int64 himagic;
	t_int64 lomagic;
	t_int64 longword;
	t_size size;

	himagic = ft_fillbytes(0x80);
	lomagic = ft_fillbytes(0x01);
	while (1)
	{
		longword = *i_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0)
		{
			size = check_terminator(longword, str);
			if (size)
				return (size);
		}
	}
}

t_size	ft_strlen(const char *str)
{
	char *c_ptr;

	if (str == NULL)
		return (0);
	c_ptr = str;
	while (((t_int64)c_ptr & (sizeof(t_int64) - 1)) != 0)
	{
		if (!*c_ptr)
			return ((t_size) (c_ptr - str));
		c_ptr++;
	}
	return (fast_strlen((t_int64*)c_ptr, str));
}
