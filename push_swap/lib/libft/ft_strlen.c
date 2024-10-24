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

#include "libft.h"

static unsigned long int fillbytes(int byte) 
{
	return (0x0101010101010101 * byte);
}

static t_size check_terminator(long int longword, const char *str)
{
	const char	*cp;
	t_size	i;

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


static t_size fast_strlen(long int *i_ptr, const char *str)
{
	t_size	size;
	long int	himagic;
	long int	lomagic;
	long int	longword;

	himagic = fillbytes(0x80);
	lomagic = fillbytes(0x01);
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
	char	*c_ptr;

	if (str == NULL)
		return (0);
	c_ptr = str;
	while (((long int)c_ptr & (sizeof(long int) - 1)) != 0)
	{
		if (!*c_ptr)
			return ((t_size) (c_ptr - str));
		c_ptr++;
	}
	return (fast_strlen((long int *)c_ptr, str));
}
