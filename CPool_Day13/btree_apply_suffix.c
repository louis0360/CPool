#include <stdlib.h>
#include "./include/btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
	btree_t *btree_ptr = root;
	if(!btree_ptr)
		return;
	if (btree_ptr->left != NULL)
	{
		btree_apply_suffix(btree_ptr->left, applyf);
	}
	if (btree_ptr->right != NULL)
	{
		btree_apply_suffix(btree_ptr->right, applyf);
	}
	(*applyf)(btree_ptr->item);
}
