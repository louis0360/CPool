#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
	linked_list_t *new = NULL;
	linked_list_t *next = NULL;
	int i = 0;
	while (i < ac)
	{
		if (!(next = malloc(sizeof(*next))))
			return (NULL);
		next->next = new;
		if (!(next->data = my_strdup(av[i])))
			return (NULL);
		new = next;
		i = i + 1;
	}
	return new;
}
