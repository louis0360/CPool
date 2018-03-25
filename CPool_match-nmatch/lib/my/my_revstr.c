#include <stdlib.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
	char tmp;
	int i,len = my_strlen(str);
	for (i=0;i<len/2;i++)
	{
		tmp = str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=tmp;
	}
	return str;
}
