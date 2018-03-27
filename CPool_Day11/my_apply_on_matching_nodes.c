#include "./include/mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin, int(*f)(), void const *data_ref, int(*cmp)())
{
	linked_list_t *list_ptr;
	list_ptr = begin;
	while(list_ptr)
	{
		if((*cmp)(list_ptr->data,data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
	return (0);
}
