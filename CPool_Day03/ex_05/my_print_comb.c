#include <unistd.h>

int my_putchar(char c);

int my_print_comb(void)
{
	char a='0',b='1',c='2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			while (c <= '9')
			{
				if (a < b && b < c)
				{
					my_putchar(a);
					my_putchar(b);
					my_putchar(c);
					if (a=='7' && b=='8' && c=='9')
						break;
					my_putchar(',');
					my_putchar(' ');
				}
				c++;
			}
			b++;
			c = '0';
		}
		a++;
		b = '0';
	}
	return (0);
}
