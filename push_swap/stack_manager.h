/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:56:07 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/03 20:56:12 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_MANAGER_H
# define STACK_MANAGER_H

# include "ps_lib.h"

void	create_stacks(t_stack **s_a, t_stack **s_b, char **params, int p_len);
void    to_first(t_stack **stack);
void    to_last(t_stack **stack);

#endif