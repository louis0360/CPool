#include "../include/my.h"

int my_mod(char *nb1, char *nb2)
{
	int res;
	if(my_getnbr(nb2) != 0)
	{
		res = my_getnbr(nb1) % my_getnbr(nb2);
		my_put_nbr(res);
		my_putchar('\n');
		return 0;
	}
	else
	{
		my_putstr("Stop: modulo by zero\n");
		return -1;
	}
}
