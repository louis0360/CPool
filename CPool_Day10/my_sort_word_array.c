#include "./include/my.h"

int my_sort_word_array(char **tab)
{
	int i = 0;
	int j;
	char *tmp;
	while(tab[i])
	{
		i++;
	}
	i--;
	while(i > 0)
	{
		j = 0;
		while (j < i)
		{
			if(my_strcmp(tab[j],tab[j+1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = tmp;
			}
			++j;
		}
		--i;
	}
	return 0;
}
