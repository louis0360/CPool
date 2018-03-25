int nmatch(char const *s1, char const *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*')
	{
		if (!*s1)
			return (nmatch(s1, s2 + 1));
		else
			return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	}
	if (*s1 != *s2)
		return (0);
	return (nmatch(s1 + 1, s2 + 1));
}
