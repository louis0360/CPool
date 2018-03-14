#include <stdlib.h>

int my_strlen(char const *str);

int my_strcmp(const char *s1, const char *s2)
{
	while(*s1==*s2)
	{
		if(*s1=='\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1-*s2;
}

char *my_strcat(char *dest, const char src)
{
	if(dest!=NULL)
	{
		char *p=dest;
		while(*p!='\0')
		{
			p++;
		}
		*p++=src;
		*p='\0';
	}
	return dest;
}

int my_compare(char *s1,char *s2)
{
	if(my_strlen(s1) > my_strlen(s2))
		return 1;
	if(my_strlen(s1) == my_strlen(s2))
	{
		if(my_strcmp(s1,s2) > 0)
			return 1;
		if(my_strcmp(s1,s2) == 0)
			return 0;
		if(my_strcmp(s1,s2) < 0)
			return -1;
	}
	return -1;
}

int my_getnbr(char const *str)
{
	int i = 0;
	int flag = 1;
	int nbr = 0;
	char *tmp = malloc(30);

	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		my_strcat(tmp,str[i]);
		i++;
	}
	if (my_compare(tmp,"2147483647") > 0)
		return 0;
	else
		return (nbr * flag);
}
