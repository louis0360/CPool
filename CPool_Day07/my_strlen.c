int my_strlen(char const *str)
{
	int i=0;
	while (*str!='\0')
	{
		str++;
		i++;
	}
	return i;
}
