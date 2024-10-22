/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:00:15 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/01/22 13:05:36 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

static int	in_range(int x, int a, int b)
{
	int	max;
	int	min;

	max = b;
	min = b;
	if (a > b)
		max = a;
	else
		min = a;
	if (x >= min && x <= max)
		return (1);
	return (0);
}

static int	check_negative(const char *s, int *sign)
{
	int	i;

	i = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int			sign;
	long int	i_out;

	i_out = 0;
	sign = 1;
	if (!*str)
		return (0);
	while (*str == 32 || in_range(*str, 8, 15))
		str++;
	str += check_negative(str, &sign);
	while (ft_isdigit(*str))
	{
		i_out = i_out * 10 + (*str - 48);
		str++;
	}
	return (i_out * sign);
}
