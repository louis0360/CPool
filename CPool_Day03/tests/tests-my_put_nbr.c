#include "my_put_nbr.h"

int my_putchar(char c);

int main()
{
	my_put_nbr(42);
	my_putchar('\n');
	my_put_nbr(0);
	my_putchar('\n');
	my_put_nbr(-2147483647);
	return (0);
}
