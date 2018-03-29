#include <stdlib.h>
#include "./include/btree.h"

btree_t *btree_create_node(void *item)
{
	btree_t *node;
	node = malloc(sizeof(*node));
	if(node == NULL)
	{
		return NULL;
	}
	node->item = my_strdup(item);
	node->left = 0;
	node->right = 0;
	return node;
}
