#include "containers/stack.h"
#include "pushswap_functions.h"

int double_swap(stack_t *stack1, stack_t *stack2) {
	if (stack1->length <= 1 || stack2->length <= 1)
		return (0);
	swap_stack(stack1);
	swap_stack(stack2);
	return (2);
}

int double_rotate(stack_t *stack1, stack_t *stack2) {
	if (stack1->length <= 1 || stack2->length <= 1)
		return (0);
	rotate_stack(stack1);
	rotate_stack(stack2);
	return (2);
}

int double_reverse_rotate(stack_t *stack1, stack_t *stack2) {
	if (stack1->length <= 1 || stack2->length <= 1)
		return (0);
	reverse_rotate_stack(stack1);
	reverse_rotate_stack(stack2);
	return (2);
}