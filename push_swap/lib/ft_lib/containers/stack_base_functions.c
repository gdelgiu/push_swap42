#include "stack.h"

int alloc_stack(stack_t **stack) {
	if (!stack)
		return (0);
	*stack = (stack_t *) calloc(1, sizeof(stack_t));
	if (!*stack) 
		return (0);
	return (1);
}

int push_stack(stack_t *stack, void *content) 
{
	node_t *node;
	
	if (!stack || !content)
		return (0);
	node = new_node(content);
	if (!node)
		return (0);
	if (!stack->top) 
	{
		stack->top = node;
		stack->bottom = stack->top;
	} 
	else 
	{
		node->next = stack->top;
		stack->top = node;
	}
	stack->length++;
	return (1);
}

void *pop_stack(stack_t *stack) {
	node_t *tmp;
	void *ret;
	
	if (!stack || !stack->top)
		return (NULL);
	tmp = stack->top;
	ret = tmp->content;
	stack->top = stack->top->next;
	stack->length--;
	if (!stack->length)
		stack->bottom = NULL;
	free(tmp);
	return (ret);
}

void free_stack(stack_t *stack) 
{
	node_t *tmp;
	
	if (!stack)
		return;
	while (stack->top) 
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}