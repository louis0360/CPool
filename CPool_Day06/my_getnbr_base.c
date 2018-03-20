int my_strlen(char const *str);

int	find_pos(char c, char const *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return -1;
}

int is_unique(char const *str)
{
	int len = my_strlen(str);
	int i,j;
	for(i = 0; i < len - 1; i++)
		for(j = i + 1; j < len; j++)
			if(str[i] == str[j])
				return 0;
	return 1;
}

int my_getnbr_base(char const *str, char const *base)
{
	int nb = 0;
	int i;
	int fac = 1;

	if(!str || !base)
		return 0;
	if(!is_unique(base))
		return 0;
	for(i = 0; str[i]; i++)
	{
		if(find_pos(str[i], base)==-1)
			return 0;
	}
	
	if (str[0] == '+')
		return my_getnbr_base(&str[1], base);
	if (str[0] == '-')
		return (-my_getnbr_base(&str[1], base));
	for (i = my_strlen(str) - 1; i >= 0; i--)
	{
		nb = nb + find_pos(str[i], base) * fac;
		fac *= my_strlen(base);
	}
	return (nb);
}
