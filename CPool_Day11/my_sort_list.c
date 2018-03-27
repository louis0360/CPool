#include <stdlib.h>
#include "./include/mylist.h"

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
	linked_list_t *list_ptr;
	linked_list_t *next;
	void *tmp;

	if(begin != NULL && *begin != NULL)
	{
		list_ptr = *begin;
		next = (*begin)->next;
		while (next != NULL)
		{
			if ((*cmp)(list_ptr->data, next->data) > 0)
			{
				tmp = list_ptr->data;
				list_ptr->data = next->data;
				next->data = tmp;
				list_ptr = *begin;
				next = (*begin)->next;
			}
			else
			{
				list_ptr = list_ptr->next;
				next = next->next;
			}
		}
	}
}
