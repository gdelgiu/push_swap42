/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:16:06 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/03/01 21:21:10 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIB_H
# define PS_LIB_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#include "utils.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void    push(t_stack **from, t_stack **to, char *act);

void    swap(void *stack);

void    reverse(void *stack);

void    rreverse(void *stack);

#endif
