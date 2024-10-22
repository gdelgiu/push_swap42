/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:56:17 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/01/22 14:33:23 by gdel-giu         ###   ########.fr       */
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

int	ft_isdigit(char c)
{
	if (in_range(c, 48, 57))
		return (1);
	return (0);
}
