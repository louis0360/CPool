#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
	char *dest;
	int len;

	len = my_strlen(src);
	dest = malloc(len + 1);
	len = 0;
	while (src[len] != '\0')
	{
		dest[len] = src[len];
		len = len + 1;
	}
	dest[len] = '\0';
	return (dest);
}
