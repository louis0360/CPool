#include "../include/my.h"

int my_add(char *nb1, char *nb2);
int my_sub(char *nb1, char *nb2);
int my_mul(char *nb1, char *nb2);
int my_div(char *nb1, char *nb2);
int my_mod(char *nb1, char *nb2);

int do_op(char *nb1, char *op, char *nb2)
{
	int (*fp[5])(char*, char*);
	fp[0] = &my_add;
	fp[1] = &my_sub;
	fp[2] = &my_mul;
	fp[3] = &my_div;
	fp[4] = &my_mod;
	if(op[0] == '+')
	{
		fp[0](nb1, nb2);
		return 0;
	}
	else if(op[0] == '-')
	{
		fp[1](nb1, nb2);
		return 0;
	}
	else if(op[0] == '*')
	{
		fp[2](nb1, nb2);
		return 0;
	}
	else if(op[0] == '/')
	{
		return fp[3](nb1, nb2);
	}
	else if(op[0] == '%')
	{
		return fp[4](nb1, nb2);
	}
	else
	{
		my_putstr("0\n");
		return -1;
	}
}
