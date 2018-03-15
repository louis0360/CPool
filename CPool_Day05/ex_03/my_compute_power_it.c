int my_compute_power_it(int nb, int p)
{
	int	res;
	int	count;

	if (p == 0)
		return 1;
	if (p < 0)
		return 0;
	res = nb;
	count = 0;
	while (count < p - 1)
	{
		res *= nb;
		count++;
	}
	return res;
}
