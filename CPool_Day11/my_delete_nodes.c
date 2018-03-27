#include <stdlib.h>
#include "./include/mylist.h"

linked_list_t *my_delete_node(linked_list_t *begin, void *data_ref, int (*cmp)())
{
	linked_list_t *p;
	if(begin == NULL)
		return NULL;
	if((*cmp)(begin->data, data_ref) == 0)
	{
		p = begin->next;
		free(begin->data);
		free(begin);
		p = my_delete_node(begin->next, data_ref, cmp);
		return p;
	}
	else
	{
		begin->next = my_delete_node(begin->next, data_ref, cmp);
		return begin;
	}
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
	linked_list_t *list_ptr;
	if(begin == NULL || *begin == NULL)
		return -1;
	list_ptr = my_delete_node((*begin), (void *)data_ref, cmp);
	*begin = list_ptr;
	return 0;
}
