void my_sort_int_array(int *array, int size)
{
	int i = size - 1;
	int j;
	int tmp;
	
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if(array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
			++j;
		}
		--i;
	}
}
