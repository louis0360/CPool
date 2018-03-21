int my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

int main(int argc, char *argv[])
{
	int i = argc - 1;
	int j;
	char *tmp;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if(my_strcmp(argv[j],argv[j+1]) > 0)
			{
				tmp = argv[j];
				argv[j] = argv[j+1];
				argv[j+1] = tmp;
			}
			++j;
		}
		--i;
	}
	for(j = 0;j < argc; j++)
	{
		my_putstr(argv[j]);
		my_putchar('\n');
	}
	return 0;
}
