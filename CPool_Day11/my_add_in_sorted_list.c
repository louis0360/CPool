#include <stdlib.h>
#include "./include/mylist.h"

void my_add_in_sorted_list(linked_list_t **begin, void *data, int (*cmp)())
{
	linked_list_t *new;
	linked_list_t *temp;
	if (begin != NULL && *begin != NULL)
	{
		temp = (*begin);
		new = malloc(sizeof(*new));
		if(new == NULL)
			return;
		new->data = data;
		while ((*begin)->next != NULL && ((*cmp)((*begin)->next->data, data) < 0))
			(*begin) = (*begin)->next;

		if ((*cmp)(temp->data, data) > 0)
		{
			(*begin) = temp;
			new->next = (*begin);
			(*begin)->next = temp->next;
			(*begin) = new;
		}
		else
		{
			new->next = (*begin)->next;
			(*begin)->next = new;
			(*begin) = temp;
		}
	}
}
