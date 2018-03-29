#include <stdlib.h>

int my_strlen(char const *str);

int number_of_word(char const *str)
{
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) 
	{
		if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) &&
			!((str[i+1] >= 'a' && str[i+1] <= 'z') || (str[i+1] >= 'A' && str[i+1] <= 'Z') || (str[i+1] >= '0' && str[i+1] <= '9')))
			count++;
	}
	return (count);
}

char **my_str_to_word_array(char const *str)
{
	char **dest = malloc(sizeof(char*) * (number_of_word(str) + 1));
	int i = 0;
	int j = 0;
	int k = 0;

	while (str[i] != '\0') 
	{
		dest[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
		while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
			i++;
		k = 0;
		while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			dest[j][k] = str[i];
			i++;
			k++;
		}
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
