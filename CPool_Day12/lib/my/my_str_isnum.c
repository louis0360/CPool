int my_str_isnum(char const *str)
{
	while(*str)
	{
		if(!(*str >= '0' && *str <= '9'))
			return 0;
		str++;
	}
	return 1;
}
