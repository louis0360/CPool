char *my_strstr(char *str, char const *to_find)
{
	int i = 0;

	if (str[i])
	{
		while (to_find[i])
		{
			if (to_find[i] != str[i])
				return (my_strstr(str + 1, to_find));
			i++;
		}
		return (str);
	}
	else
		return "\0";
}
