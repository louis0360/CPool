#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb);

int my_print_comb2(void)
{
	int a = 0, b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			if(a < b)
			{
				if(a>=0 && a<=9)
					my_putchar('0');
				my_put_nbr(a);
				my_putchar(' ');
				if(b>=0 && b<=9)
					my_putchar('0');
				my_put_nbr(b);
				if (a==98 && b==99)
					break;
				my_putchar(',');
				my_putchar(' ');
			}
			b++;
		}
		a++;
		b = 0;
	}
	return 0;
}
