/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:48:11 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/01 22:48:17 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_PARAMS_H
# define CHECK_PARAMS_H

int     all_params_are_nums(char **params);
int     all_params_are_int(int n, char **params, int *param_array);
int     all_params_are_unique(int n, int *params);

int     check_params(int n, char **params);

char    **get_all_params(char **from, int *quantity);

#endif
