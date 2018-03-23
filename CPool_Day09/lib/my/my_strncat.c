#include <stdlib.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
	int dest_len = my_strlen(dest);
	int i;

	if(dest != NULL && src != NULL)
	{
		for (i = 0 ; i < nb && src[i] != '\0' ; i++)
			dest[dest_len + i] = src[i];
		dest[dest_len + i] = '\0';
	}
	return dest;
}

