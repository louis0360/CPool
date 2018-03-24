#include "../include/my.h"

int my_mul(char *nb1, char *nb2)
{
	int res;
	res = my_getnbr(nb1) * my_getnbr(nb2);
	my_put_nbr(res);
	my_putchar('\n');
	return 0;
}
