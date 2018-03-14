#include <unistd.h>

int my_putchar(char c);

int my_print_digits(void)
{
	char i;
	i = '0';
	while(i <= '9')
	{
		my_putchar(i);
		i++;
	}
	return (0);
}
