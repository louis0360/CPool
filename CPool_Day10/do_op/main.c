
int do_op(char *nb1, char *op, char *nb2);

int main(int argc, char **argv)
{
	if(argc == 4)
	{
		if(do_op(argv[1], argv[2], argv[3]) == -1)
			return 84;
		else
			return 0;
	}
	else
		return 84;
}
