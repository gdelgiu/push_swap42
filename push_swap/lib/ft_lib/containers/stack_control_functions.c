#include "stack.h"

int rotate_stack(stack_t *stack) {
    if (!stack || !stack->top || stack->top == stack->bottom)
        return (0);
    stack->bottom->next = stack->top;
    stack->top = stack->top->next;
    stack->bottom = stack->bottom->next;
    stack->bottom->next = NULL;
    return (1);
}

int reverse_rotate_stack(stack_t *stack) {
    node_t *tmp;
    
    if (!stack || !stack->top || stack->top == stack->bottom)
        return (0);
	tmp = stack->top;
    while (tmp->next != stack->bottom)
		tmp = tmp->next;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = tmp;
	stack->bottom->next = NULL;
	return (1);
}

int swap_stack(stack_t *stack) {
	node_t *tmp;
	
	if (!stack || !stack->top || stack->top == stack->bottom)
        return (0);
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
	return (1);
}

int push_to_stack(stack_t *from, stack_t *to) {
	void *content = pop_stack(from);
	if (!content)
		return (0);
	return (push_stack(to, content));
}
