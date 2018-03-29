int my_strncmp(char const *s1, char const *s2, int n)
{
	int i;
	for(i = 0;i < n && *s1 == *s2;s1++,s2++,i++)
	{
		if(*s1 == '\0')
		{
			return 0;
		}
	}
	if(i == n)
	{
		s1--;
		s2--;
	}
	return *s1 - *s2;
}
