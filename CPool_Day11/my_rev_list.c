#include <stdlib.h>
#include "./include/mylist.h"

void my_rev_list(linked_list_t **begin)
{
	linked_list_t *list_ptr;
	linked_list_t *tmp;
	list_ptr = *begin;
	*begin = NULL;
	while (list_ptr != NULL)
	{
		tmp = list_ptr->next;
		list_ptr->next = *begin;
		*begin = list_ptr;
		list_ptr = tmp;
	}
}
