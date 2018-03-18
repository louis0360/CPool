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

int n_star_last_line(int size)
{
	if (size == 0)
		return 0;
	if (size == 1)
		return 7;
	else
		return n_star_last_line(size - 1) + 2 * (size - size/2 + 2);
}

int n_space(int size)
{
	if(size == 1)
		return 0;
	if(size == 2)
		return 3;
	return n_space(size-1) + ((size-1)/2) + 3;
}

void graph_tree(int size, int space)
{
	int i = 3 + size;
	int j = size;
	int last_num = n_star_last_line(size);
	int star_num = last_num - 2*(size + 2);

	while (i > 0)
	{
		my_print_n_char(' ', j + space + 2);
		j--;
		my_print_n_char('*', star_num);
		star_num += 2;
		my_putchar('\n');
		i--;
	}
}

void graph_tree2(int size)
{
	int i = 1;
	int space = n_space(size);
	while (i <= size)
	{
		graph_tree(i, space);
		i++;
		space = space - (i+1)/2 - 2;
	}
}

void graph_root(int size)
{
	int num = n_star_last_line(size);
	int i = 0;
	while (i<size)
	{
		my_print_n_char(' ',(num-1)/2-size/2);
		my_print_n_char('|',size%2==0?size+1:size);
		my_putchar('\n');
		i++;
	}
}

void tree(int size)
{
	if(size > 0)
	{
		graph_tree2(size);
		graph_root(size);
	}
}

