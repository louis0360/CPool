int match(char const *s1, char const *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*')
	{
		if (!*s1)
			return (match(s1, s2 + 1));
		else
			return (match(s1 + 1, s2) || match(s1, s2 + 1));
	}
	if (*s1 != *s2)
		return (0);
	return (match(s1 + 1, s2 + 1));
}
