#include "./include/btree.h"

void btree_apply_level_rec(btree_t *node, int *lvl_first, int n, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (node)
	{
		if (n == 0)
			applyf(node->item, lvl_first[0], lvl_first[1]);
		else
		{
			lvl_first[1] = 0;
			btree_apply_level_rec(node->left, lvl_first, n - 1, applyf);
			lvl_first[1] = 1;
			btree_apply_level_rec(node->right, lvl_first, n - 1, applyf);
		}
	}
}

void btree_apply_by_level(btree_t *root, void (*applyf)(void *item, int level, int is_first_elem))
{
	int i;
	int max;
	int lvl_first[2];

	i = 0;
	max = btree_level_count(root);
	while (i < max)
	{
		lvl_first[0] = i;
		lvl_first[1] = 0;
		btree_apply_level_rec(root, lvl_first, i, applyf);
		i++;
	}
}
