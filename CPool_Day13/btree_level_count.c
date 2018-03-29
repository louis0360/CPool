#include <stddef.h>
#include "./include/btree.h"

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

size_t btree_level_count(btree_t const *root)
{
	if (!root)
		return (0);
	return (1 + max(btree_level_count(root->left),btree_level_count(root->right)));
}
