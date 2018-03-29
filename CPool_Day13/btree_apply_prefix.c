#include <stdlib.h>
#include "./include/btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
	btree_t *btree_ptr = root;
	if(!btree_ptr)
		return;
	(*applyf)(btree_ptr->item);
	if (btree_ptr->left != NULL)
	{
		btree_apply_prefix(btree_ptr->left, applyf);
	}
	if (btree_ptr->right != NULL)
	{
		btree_apply_prefix(btree_ptr->right, applyf);
	}
}
