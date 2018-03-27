#include <stdlib.h>
#include "./include/mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
	linked_list_t *list_ptr;
	list_ptr = *begin1;
	if (begin1 != NULL && *begin1 != NULL)
	{
		while(list_ptr->next)
		{
			list_ptr = list_ptr->next;
		}
		list_ptr->next = begin2;
	}
}
