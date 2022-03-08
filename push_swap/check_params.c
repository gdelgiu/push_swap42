/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:46:31 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/01 22:46:36 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"
#include "utils.h"

int	all_params_are_nums(char **params)
{
	int i;
	int j;

	i = 0;
	while (params[++i])
	{
		j = 0;
		if (params[i][j] == '+' || params[i][j] == '-')
				j++;
		while (params[i][j])
		{
			if (ft_isdigit(params[i][j]))
				j++;
			else
				return 0;
		}
	}
	return 1;
}

int	all_params_are_int(int n, char **params, int **param_array)
{
	int		i;
	long	param;

	*param_array = (int *) malloc((n - 1) * sizeof(int));
	i = 0;
	while (params[++i])
	{
		param = ft_atol(params[i]);
		if (param > INT_MAX || param < INT_MIN)
		{
			free(*param_array);
			return 0;
		}
		*(*param_array + i - 1) = (int) param;
	}
	return 1;
}

int	all_params_are_unique(int n, int *params)
{
	int i;
	int j;

	i = 0;
	while (i <= (n - 2))
	{
		j = 0;
		while ((i + j) <= (n - 2))
		{
			j++;
			//printf("%d == %d\n", params[i], params[i + j]);
			if (params[i] == params[i + j])
				return 0;
		}
		i++;
	}
	return 1;
}

int	check_params(int n, char **params)
{
	int		*param_array;

	if (!all_params_are_nums(params))
		return 0;
	if (!all_params_are_int(n, params, &param_array))
		return 0;
	if (!all_params_are_unique(n, param_array))
		return 0;
	free(param_array);
	return 1;
}
