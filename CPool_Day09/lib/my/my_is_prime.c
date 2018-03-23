int my_is_div(int a, int b)
{
	if (b == a - 1)
		return 0;
	if (a % b == 0)
		return 1;
	return my_is_div(a, b + 1);
}

int my_is_prime(int nb)
{
	if(nb < 2)
		return 0;
	if(nb == 2)
		return 1;
	return !my_is_div(nb, 2);
}
