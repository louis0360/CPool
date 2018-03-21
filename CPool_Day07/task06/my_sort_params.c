#include <stdlib.h>

int my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

typedef struct  List
	{
		struct List *next;
		struct List *prev;
		char        *val;
	}           List;

List *push_item(List *list, char *s)
{
	List *new = (List *)malloc(24);
	if(new!=NULL)
	{
		new->val = s;
		if(list!=NULL)
		{
			List *p = list;
			while(p->next!=NULL)
			{
				if(my_strcmp(p->next->val,s)<0)
				{
					p = p->next;
				}
				else
					break;
			}
			if(my_strcmp(p->val,s)<0)
			{
				new->prev=p;
				new->next=p->next;
				if(p->next!=NULL)
					p->next->prev=new;
				p->next=new;
			}
			else
			{
				new->prev=p->prev;
				new->next=p;
				p->prev=new;
				return new;
			}
		}
		else
		{
			new->prev = NULL;
			new->next = NULL;
			return new;
		}
	}
	return list;
}

void free_list(List *list)
{
	while(list->next!=NULL)
    {
		list = list->next;
		free(list->prev);
	}
	free(list);
}

void display_list_from_beginning(List *list)
{
    while(list!=NULL)
    {
		my_putstr(list->val);
		if(list->next!=NULL)
			my_putchar('\n');
		list = list->next;
	}
}

int main(int argc, char *argv[])
{
	List *my_list = NULL;
	int i = 0;
	while(i < argc)
	{
		my_list = push_item(my_list,argv[i]);
		i++;
	}
	display_list_from_beginning(my_list);
	my_putchar('\n');
	free_list(my_list);
	return 0;
}
