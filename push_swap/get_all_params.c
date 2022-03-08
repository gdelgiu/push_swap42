/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:34:52 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/08 19:34:55 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <unistd.h>
#include <stdio.h>

char    **add_params(char **from, char **to, int n)
{
    char    **temp;
    int     i;
    int     j;
    
    i = 0;
    temp = (char **) malloc(sizeof(char *) * (n + 1));
    if (to)
    {
        while (to[i])
        {
            temp[i] = to[i];
            free(to[i]);
            i++;
        }
        free(to);
    }
    j = -1;
    while (from[++j])
        temp[i + j] = from[j];
    temp[i + j] = NULL;
    return (temp);
}

char    **get_all_params(char **from, int *quantity)
{
    char    **all_params;
    char    **temp;
    int     i;
    int     j;

    i = 0;
    *quantity = 0;
    all_params = NULL;
    while (from[++i])
    {
        temp = ft_split(from[i], ' ');
        j = -1;
        while (temp[++j]);
        *quantity += j;
        all_params = add_params(temp, all_params, *quantity);
        free(temp);
    }
    return (all_params);
}