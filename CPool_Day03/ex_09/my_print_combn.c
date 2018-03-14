#include <unistd.h>

int my_putchar(char c);

int my_put_nbr(int nb);

int my_pow(int num, int pow)
{
	int	res;
	int	count;

	if (pow == 0)
		return 1;
	res = num;
	count = 0;
	while (count < pow - 1)
	{
		res *= num;
		count++;
	}
	return res;
}

int first_number(int n)
{
	int	number = 0;
	int	count = 0;

	n--;
	while (n - count > 0)
	{
		number += (n - count) * my_pow(10, count);
		count++;
	}
	return number;
}

void print_num(int num, int n)
{
	int	count = 0;
	int	tmp;

	while (count < n)
	{
		tmp = num / my_pow(10, n - 1 - count) % 10;
		my_put_nbr(tmp);
		count++;
	}
	if (num / my_pow(10, n - 1) < (10 - n))
	{
		my_putchar(',');
		my_putchar(' ');
	}
}

int check_num(int num, int n)
{
	int	save;
	int	tmp;

	save = num;
	tmp = num % 10;
	if (n != 1 && num < my_pow(10, n - 2))
		return -1;
	while (save / 10 != 0)
	{
		save /= 10;
		if (tmp > save % 10)
			tmp = save % 10;
		else
			return -1;
	}
	return 0;
}

int my_print_combn(int n)
{
	int	count;

	if (n > 10 || n <= 0)
		return -1;
	count = first_number(n);
	if (n == 10)
	{
		print_num(count, n);
		return 0;
	}
	while (count / my_pow(10, n - 1) <= (10 - n))
	{
		if (check_num(count, n) == 0)
			print_num(count, n);
		count++;
	}
	return 0;
}
