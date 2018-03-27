#include <stdlib.h>
#include "./include/mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref, int (*cmp)())
{
	linked_list_t *list_ptr;
	list_ptr = (linked_list_t *)begin;
	while (list_ptr != NULL) 
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return list_ptr;
		list_ptr = list_ptr->next;
	}
	return (NULL);
}
