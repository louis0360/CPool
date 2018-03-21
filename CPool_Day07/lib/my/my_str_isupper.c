int my_str_isupper(char const *str)
{
	while(*str)
	{
		if(!(*str >= 'A' && *str <= 'Z'))
			return 0;
		str++;
	}
	return 1;
}
