/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:28:46 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/01 21:28:53 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"
#include "stack_manager.h"

void    push(t_stack **from, t_stack **to, char *act)
{
    if (!(*from))
        return ;
    to_first(from);
    if (*to)
    {
        to_first(to);
        (*from)->next = *to;
    }
    else
    {
        *to = (t_stack *) malloc(sizeof(t_stack));
        (*to)->next = NULL;
        (*to)->prev = NULL;
        (*to)->content = (*from)->content;
    }
    *from = (*from)->next;
    free((*from)->prev);
    write(1, act, ft_strlen(act));
    write(1, "\n", 1);
    return ;
}