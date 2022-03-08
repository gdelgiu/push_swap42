/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:51:11 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/03 20:51:14 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"

void    to_first(t_stack **stack)
{
    while((*stack)->prev)
        *stack = (*stack)->prev;
}

void    to_last(t_stack **stack)
{
    while((*stack)->next)
        *stack = (*stack)->next;
}

void	create_stacks(t_stack **s_a, t_stack **s_b, char **params, int p_len)
{
	int i;
	t_stack *temp;

	i = 0;
	*s_a = (t_stack *) malloc(sizeof(t_stack));
    *s_b = NULL;
    (*s_a)->prev = NULL;
	while (i++ < p_len)
	{
		(*s_a)->content = ft_atol(params[i]);
        if (i + 1 <= p_len)
        {
            (*s_a)->next = (t_stack *) malloc(sizeof(t_stack));
            temp = *s_a;
            *s_a = (*s_a)->next;
            (*s_a)->prev = temp;
        }
	}
    (*s_a)->next = NULL;
    to_first(s_a);
	free(temp);
}
