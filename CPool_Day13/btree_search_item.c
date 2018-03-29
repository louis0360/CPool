#include <stdlib.h>
#include "./include/btree.h"

void *btree_search_item(btree_t const *root, void const *data_ref, int (*cmpf)())
{
	void *search;

	search = NULL;
	if (root)
	{
		search = btree_search_item(root->left, data_ref, cmpf);
		if (!search && cmpf(data_ref, root->item) == 0)
			search = (btree_t *)root;
		if (!search)
			search = btree_search_item(root->right, data_ref, cmpf);
	}
	return (search);
}
