#include <unistd.h>
#include <stdio.h>

int my_putchar(char c);
int my_strlen(char const *str);
int my_putnbr_base(int nbr, char const *base);

void my_print_n_char(char c, int n)
{
	int i = 0;
	while(i < n)
	{
		my_putchar(c);
		i++;
	}
}

int my_showmem(char const *str, int size)
{
	char c;
	int count = 0;
	int i,j;

	write(1,"00000000:  ",11);
	for (i = 0; i < size; ++i)
	{
		if (count > 15)
		{
			for (j = i-16; j < i; j++)
			{
				if(str[j] < 32 || str[j] >= 127)
					my_putchar('.');
				else
					my_putchar(str[j]);
			}
			my_putchar('\n');
			my_print_n_char('0',6-i/255);
			my_putnbr_base(i,"0123456789abcdef");
			write(1,":  ",3);
			count = 0;
		}
		++count;
		c = str[i];
		c &= 240;
		c /= 16;
		my_putnbr_base(c, "0123456789abcdef");
		c = str[i];
		c &= 15;
		my_putnbr_base(c, "0123456789abcdef");
		if(i % 2 == 1)
			my_putchar(' ');
	}
	my_print_n_char(' ',40 - 2 * count - count / 2);
	for (j = i-count; j < i; j++)
	{
		if(str[j] < 32 || str[j] >= 127)
			my_putchar('.');
		else
			my_putchar(str[j]);
	}
	my_putchar('\n');
	return (0);
}
