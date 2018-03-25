#include <stdlib.h>

int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
	int a = 0;
	int b = 0;
	int len = 0;
	int line = 0;
	char *str;

	while (a < argc) 
	{
		len = len + (my_strlen(argv[a])) + 1;
		a++;
	}
	str = malloc(sizeof(char) * len);
	a = 0;
	while (line < argc) 
	{
		while (argv[line][a] != '\0')
		{
			str[b] = argv[line][a];
			b++;
			a++;
		}
		line++;
		if (line < argc)
			str[b] = '\n';
		a = 0;
		b++;
	}
	str[b] = '\0';
	return (str);
}
