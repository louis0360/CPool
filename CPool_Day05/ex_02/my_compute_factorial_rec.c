int my_compute_factorial_rec(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	return (nb * my_compute_factorial_rec(nb - 1));
}
