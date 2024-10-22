#ifndef NODE_H
#define NODE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node_s {
	void *content;
	struct node_s *next;
} node_t;

int alloc_node(node_t **node);
node_t *new_node(void *content);
int get_node_content_as_int(node_t *n);
char *get_node_content_as_str(node_t *n);

#endif