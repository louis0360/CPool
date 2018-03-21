#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb)
{
	if(nb<0)
	{
		if(nb == -2147483648)
		{
			write(1,"-2147483648",11);
			return 0;
		}
		my_putchar('-');
		my_put_nbr(nb*(-1));
	}
	if(nb>=10)
	{
		my_put_nbr(nb/10);
		nb = nb % 10;
	}
	if(nb>=0 && nb<=9)
	{
		my_putchar(nb+'0');
	}
	return 0;
}
