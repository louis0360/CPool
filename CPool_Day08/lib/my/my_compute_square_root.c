int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb)
{
	int i = 0;
	while (i <= nb) 
	{
		if (my_compute_power_rec(i,2) == nb)
			return (i);
		i++;
	}
	return (0);
}
