#include <unistd.h>

int my_putchar(char c);

void my_print_n_char(char c, int n)
{
	int i = 0;
	while(i < n)
	{
		my_putchar(c);
		i++;
	}
}

void x_or_y_is_one(int x, int y)
{
	if (y == 1)
	{
		my_putchar('B');
		if(x != 1)
		{
			my_print_n_char('B', x-2);
			my_putchar('B');
		}
		my_putchar('\n');
	}
	if (x == 1)
	{
		if (y != 1)
		{
			my_putchar('B');
			my_putchar('\n');
			y-=2;
			while (y > 0)
			{
				my_putchar('B');
				my_putchar('\n');
				y--;
			}
			my_putchar('B');
			my_putchar('\n');
		}
    }
}

int print_line(int x, char left, char middle, char right)
{
	if (x == 2)
	{
		my_print_n_char(left, 1);
		my_print_n_char(right, 1);
	}
	if (x > 2)
	{
		my_print_n_char(left, 1);
		my_print_n_char(middle, x - 2);
		my_print_n_char(right, 1);
	}
	my_print_n_char('\n', 1);
	return (0);
}

void colle(int x, int y)
{
	if(x <= 0 || y <= 0)
	{
		write(1,"Invalid size\n",13);
		return;
	}
	if (x == 1 || y == 1)
		x_or_y_is_one(x, y);
	else
	{
		if (x > 0 && y > 0)
		{
			print_line(x, 'A', 'B', 'C');
			while (y > 2)
			{
				if (x == 2)
					print_line(x, 'B', 0, 'B');
				else
				{
					print_line(x, 'B', ' ', 'B');
				}
				y--;
			}
			print_line(x, 'A', 'B', 'C');
		}
	}
}

int main()
{
	colle(5,5);
	return (0);
}
