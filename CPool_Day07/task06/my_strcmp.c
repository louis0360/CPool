int my_strcmp(char const *s1, char const *s2)
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
