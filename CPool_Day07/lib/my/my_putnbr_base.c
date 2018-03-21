#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
	if (nbr < 0)
	{
		my_putchar('-');
		nbr = -nbr;
	}
	if (nbr > my_strlen(base) - 1)
	{
		my_putnbr_base(nbr / my_strlen(base), base);
		my_putnbr_base(nbr % my_strlen(base), base);
	}
	else
		my_putchar(base[nbr]);
	return 0;
}
