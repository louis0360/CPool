#include <stdlib.h>
#include "./include/btree.h"

rb_node_t *rb_create_node(void *data, enum RB_COLOR col)
{
	rb_node_t *node;

	node = malloc(sizeof(*node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	node->color = col;
	return (node);
}

void rb_insert_rec(rb_node_t *node, void *data, int (*cmpf)(void *, void *), enum RB_COLOR col)
{
	if (node)
	{
		if (cmpf(node->data, data) > 0)
		{
			if (node->left == NULL)
				node->left = rb_create_node(data, col);
			else
				rb_insert_rec(node->left, data, cmpf, 1 - col);
		}
		else
		{
			if (node->right == NULL)
				node->right = rb_create_node(data, col);
			else
				rb_insert_rec(node->right, data, cmpf, 1 - col);
		}
	}
}

void rb_insert(rb_node_t **root, void *data, int (*cmpf)())
{
	if (*root == NULL)
		*root = rb_create_node(data, RB_BLACK);
	else
		rb_insert_rec(*root, data, cmpf, RB_RED);
}
