char *my_strlowcase(char *str);

char *my_strcapitalize(char *str)
{
	int i = 0;
	str = my_strlowcase(str);
	while(str[i])
	{
		if(i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if((str[i] >= 7 && str[i] <= 13) || (str[i] >= 32 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64))
		{
			if(str[i+1] >= 'a' && str[i+1] <= 'z')
				str[i+1] -= 32;
		}
		i++;
	}
	return str;
}
