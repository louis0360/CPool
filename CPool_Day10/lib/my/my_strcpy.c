char *my_strcpy(char *dest, char const *src)
{
	if(dest && src)
	{
		char *p=dest;
		while(*src!='\0')
		{
			*p++=*src++;
		}
		*p='\0';
	}
	return dest;
}
