#include "../include/my.h"
#include "../include/opp.h"
#include "../include/my_opp.h"

int my_add(char *nb1, char *nb2)
{
	int res;
	res = my_getnbr(nb1) + my_getnbr(nb2);
	my_put_nbr(res);
	my_putchar('\n');
	return 0;
}

int my_sub(char *nb1, char *nb2)
{
	int res;
	res = my_getnbr(nb1) - my_getnbr(nb2);
	my_put_nbr(res);
	my_putchar('\n');
	return 0;
}

int my_div(char *nb1, char *nb2)
{
	int res;
	if(my_getnbr(nb2) != 0)
	{
		res = my_getnbr(nb1) / my_getnbr(nb2);
		my_put_nbr(res);
		my_putchar('\n');
		return 0;
	}
	else
	{
		my_putstr("Stop: division by zero\n");
		return -1;
	}
}

int my_mul(char *nb1, char *nb2)
{
	int res;
	res = my_getnbr(nb1) * my_getnbr(nb2);
	my_put_nbr(res);
	my_putchar('\n');
	return 0;
}

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

int my_usage(char *nb1, char *nb2)
{	
	int	i = 0;

	my_putstr("error : only [ ");
	while (OPERATORS_FUNCS[i].opp[0])
	{
		my_putstr(OPERATORS_FUNCS[i].opp);
		my_putchar(' ');
		i++;
	}
	my_putstr("] are supported\n");
	return -1;
}

int do_op(char *nb1, char *op, char *nb2)
{
	int i = 0;
	while(OPERATORS_FUNCS[i].opp[0])
	{
		if(op[0] == OPERATORS_FUNCS[i].opp[0])
			break;
		i++;
	}
	return OPERATORS_FUNCS[i].fct(nb1, nb2);
}

