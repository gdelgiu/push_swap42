#include "node.h"

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