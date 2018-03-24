int my_advanced_sort_word_array(char **tab, int(*cmp)(char const *, char const *))
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
			if((*cmp)(tab[j],tab[j+1]) > 0)
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
