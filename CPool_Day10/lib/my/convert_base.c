#include <stdlib.h>

int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_getnbr_base(char const *str, char const *base);
char *my_strcat2(char *dest, char const src);
int is_unique(char const *str);

void my_convertnbr_base_rec(long nbr, char const *base, int len, char *str)
{
	if (nbr > len - 1)
	{
		my_convertnbr_base_rec(nbr / len, base, len, str);
		my_convertnbr_base_rec(nbr % len, base, len, str);
	}
	else
		str = my_strcat2(str,base[nbr]);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
	long inbr;
	char *str;

	str = malloc(sizeof(char) * 65);
	inbr = my_getnbr_base(nbr, base_from);
	if(!base_to)
		return "0";
	if(!is_unique(base_to))
		return "0";
	if(my_strlen(base_to) < 2)
		return "0";
	if (inbr < 0)
	{
		my_strcat(str, "-");
		inbr = -inbr;
	}
	my_convertnbr_base_rec(inbr, base_to, my_strlen(base_to), str);
	return (str);
}
