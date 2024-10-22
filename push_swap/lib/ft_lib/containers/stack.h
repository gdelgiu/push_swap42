#ifndef STACK_H
#define STACK_H

#include "node.h"

typedef struct stack_s {
    size_t length;
    node_t *top;
    node_t *bottom;
} stack_t;

int alloc_stack(stack_t **stack);
int push_stack(stack_t *stack, void *content);
void *pop_stack(stack_t *stack);
void free_stack(stack_t *stack);
int rotate_stack(stack_t *stack);
int reverse_rotate_stack(stack_t *stack);
int swap_stack(stack_t *stack);
int push_to_stack(stack_t *from, stack_t *to);

#endif