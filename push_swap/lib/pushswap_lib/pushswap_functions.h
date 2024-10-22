#ifndef PUSHSWAP_FUNCTIONS_H
#define PUSHSWAP_FUNCTIONS_H 

# include "commands.h"
# include "containers/stack.h" 

int double_swap(stack_t *stack1, stack_t *stack2);
int double_rotate(stack_t *stack1, stack_t *stack2);
int double_reverse_rotate(stack_t *stack1, stack_t *stack2);

int double_pushswap(stack_t *stack_a, stack_t *stack_b, t_ps_comm cmd);
int pushswap(stack_t *stack_a, stack_t *stack_b, t_ps_comm cmd) {


#endif