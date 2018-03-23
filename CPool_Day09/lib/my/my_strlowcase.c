char *my_strlowcase(char *str)
{
	char *p = str;
	while(*p)
	{
		if(*p >= 'A' && *p <= 'Z')
			*p += 32;
		p++;
	}
	return str;
}
