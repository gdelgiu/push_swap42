/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:13:35 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/02/28 20:14:27 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib.h"
#include "check_params.h"
#include "stack_manager.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	push(&stack_a, &stack_b, "pb");
	printf("A : %d, B : %d\n", stack_a->content, stack_b->content);
	return ;
}

int		main(int ac, char **av)
{
	//t_stack	*stack_a;
	//t_stack	*stack_b;
	char	**all_params;
	int		params_count;

	if (ac < 2)
		return 0;
	all_params = get_all_params(av, &params_count);
	if (!check_params(params_count, all_params))
		return 0;
	printf("passed");
	/*create_stacks(&stack_a, &stack_b, av, ac - 1);
	push_swap(stack_a, stack_b);*/
	return 0;
}
