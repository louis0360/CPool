#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
	if(dest != NULL && src != NULL)
	{
		char *p=dest;
		while(*p!='\0')
		{
			p++;
		}
		while(*src!='\0')
		{
			*p++=*src++;
		}
		*p='\0';
	}
	return dest;
}
