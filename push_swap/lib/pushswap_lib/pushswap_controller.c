#include "pushswap_functions.h"

int double_pushswap(stack_t *stack_a, stack_t *stack_b, t_ps_comm cmd) {
	int result;
	
	if (cmd == SSWAP)
		result = double_swap(stack_a, stack_b);
	else if (cmd == RROTT)
		result = double_rotate(stack_a, stack_b);
	else if (cmd == RRROT)
		result = double_reverse_rotate(stack_a, stack_b);
	else
		result = 0;
	if (result)
		double_print_cmd(cmd);
	return (result);
}

int pushswap(stack_t *stack_a, stack_t *stack_b, t_ps_comm cmd) {
	int result;
	
	if (cmd == PUSHA)
		result = push_to_stack(stack_b, stack_a);
	else if (cmd == PUSHB)
		result = push_to_stack(stack_a, stack_b);
	else if (cmd == SWAPA)
		result = swap_stack(stack_a);
	else if (cmd == SWAPB)
		result = swap_stack(stack_b);
	else if (cmd == ROTTA)
		result = rotate_stack(stack_a);
	else if (cmd == ROTTB)
		result = rotate_stack(stack_b);
	else if (cmd == RROTA)
		result = reverse_rotate_stack(stack_a);
	else if (cmd == RROTB)
		result = reverse_rotate_stack(stack_b);
	else
		result = double_pushswap(stack_a, stack_b, cmd);
	if (result && result != 2)
		print_cmd(cmd);
	return (result);
}