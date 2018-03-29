#include <stdlib.h>
#include "./include/btree.h"

void btree_apply_infix(btree_t *root, int (*applyf)(void *))
{
	btree_t *btree_ptr = root;
	if(!btree_ptr)
		return;
	if (btree_ptr->left != NULL)
	{
		btree_apply_infix(btree_ptr->left, applyf);
	}
	(*applyf)(btree_ptr->item);
	if (btree_ptr->right != NULL)
	{
		btree_apply_infix(btree_ptr->right, applyf);
	}
}
