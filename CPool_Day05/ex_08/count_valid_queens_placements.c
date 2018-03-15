int my_abs (int n)
{
	if(n>=0)
		return n;
	else
		return -n;
}

int check(int *queen, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(queen[i] == queen[n] || my_abs(queen[i] - queen[n]) == (n - i))
        {
            return 1;
        }
    }
    return 0;
}

void put(int *queen, int row, int *sum, int n)
{
    if(row == n)
        (*sum)++;
    for(int i = 0; i < n; i++)
    {
        queen[row] = i;
        if(!check(queen,row))
        {
            put(queen, row + 1, sum, n);
        }
    }
}

int count_valid_queens_placements (int n)
{
    int queen[n], sum=0;
    put(queen, 0, &sum, n);
    return sum;
}
