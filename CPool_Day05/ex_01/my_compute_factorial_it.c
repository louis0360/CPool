int my_compute_factorial_it(int nb)
{
	int a =	nb - 1;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	else
	{
		while (a > 0)
		{
			nb = nb * a;
			a--;
		}
		return (nb);
	}
}
