int my_str_isprintable(char const *str)
{
	while(*str)
	{
		if(*str < 32 || *str >= 127)
			return 0;
		str++;
	}
	return 1;
}
