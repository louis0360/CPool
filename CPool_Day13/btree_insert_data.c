#include "./include/btree.h"

void btree_insert_data(btree_t **root, void *item, int (*cmpf)())
{
	if (*root)
	{
		if ((*cmpf)((*root)->item, item) >= 0)
			btree_insert_data(&(*root)->left, item, cmpf);
		else
			btree_insert_data(&(*root)->right, item, cmpf);
	}
	else
		*root = btree_create_node(item);
}
