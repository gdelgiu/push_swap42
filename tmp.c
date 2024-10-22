#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// node header

typedef struct node_s {
    void *content;
    struct node_s *next;
} node_t;

int alloc_node(node_t **node) {
    if (!node)
        return (0);
    *node = (node_t *) calloc(1, sizeof(node_t));
    if (!*node)
        return (0);
    return (1);
}

node_t *new_node(void *content) {
    node_t *new;
    
    if (!alloc_node(&new))
        return (NULL);
    new->content = content;
    return (new);
}


int get_node_content_as_int(node_t *n) {
	return (*(int *)n->content);
}

char *get_node_content_as_str(node_t *n) {
	return ((char *)n->content);
}

// stack header 

typedef struct stack_s {
    size_t length;
    node_t *top;
    node_t *bottom;
} stack_t;

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

// stack control functions

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

// pushswap wrapper func

enum PS_COMMANDS {
	PUSHA,
	PUSHB,
	SWAPA,
	SWAPB,
	ROTTA,
	ROTTB,
	RROTA,
	RROTB,
	SSWAP,
	RROTT,
	RRROT
};

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

void double_print_cmd(PS_COMMANDS cmd) {
	if (cmd == SSWAP)
		printf("ss\n");
	else if (cmd == RROTT)
		printf("rr\n");
	else if (cmd == RRROT)
		printf("rrr\n");
	else
		(void) cmd;
}

void print_cmd(PS_COMMANDS cmd) {
	if (cmd == PUSHA)
		printf("pa\n");
	else if (cmd == PUSHB)
		printf("pb\n");
	else if (cmd == SWAPA)
		printf("sa\n");
	else if (cmd == SWAPB)
		printf("sb\n");
	else if (cmd == ROTTA)
		printf("ra\n");
	else if (cmd == ROTTB)
		printf("rb\n");
	else if (cmd == RROTA)
		printf("rra\n");
	else if (cmd == RROTB)
		printf("rrb\n");
	else
		(void) cmd;
}

int double_pushswap(stack_t *stack_a, stack_t *stack_b, PS_COMMANDS cmd) {
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

int pushswap(stack_t *stack_a, stack_t *stack_b, PS_COMMANDS cmd) {
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
