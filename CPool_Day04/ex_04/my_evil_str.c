#include <stdlib.h>

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
	int len=my_strlen(str);
	char *tmp=malloc(len);
	char *p = tmp;
	while(len>0)
	{
		*p=str[len-1];
		len--;
		p++;
	}
	*p='\0';
	return tmp;
}
