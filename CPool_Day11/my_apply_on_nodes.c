#include <stdlib.h>
#include "./include/mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
	linked_list_t *list_ptr;
	list_ptr = begin;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
	return (0);
}
