int my_str_isalpha(char const *str)
{
	while(*str)
	{
		if(!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return 0;
		str++;
	}
	return 1;
}
