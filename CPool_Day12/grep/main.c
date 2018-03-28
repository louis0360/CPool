#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../include/my.h"

char *get_next_line(const int fd);

int my_puterrstr(char const *str)
{
	return write(2,str,my_strlen(str));
}

int my_argc_two(char const *str)
{
	char buffer[512];
	int size = 1;

	while (size > 0) 
	{
		for (int i = 0; i < 512; ++i)
			buffer[i] = '\0';
		size = read(0, buffer, 511);
		if(size == -1)
			return -1;
		if (my_strstr(buffer,str))
		{
			my_putstr(buffer);
		}
	}
	return 0;
}

int my_grep(char const *str, char const *file)
{
	int fd;
	char *line = "";
	fd = open(file,O_RDONLY);
	if (fd != -1)
	{
		while(line!=NULL)
		{
			line = get_next_line(fd);
			if(line)
			{
				if(my_strstr(line,str))
				{
					my_putstr(line);
					my_putchar('\n');
				}
			}
		}
		close(fd);
		return 0;
	}
	else
	{
		if(errno == 2)
		{
			my_puterrstr("grep: ");
			my_puterrstr(file);
			my_puterrstr(": No such file or directory\n");
		}
		if(errno == 13)
		{
			my_puterrstr("grep: ");
			my_puterrstr(file);
			my_puterrstr(": Permission denied\n");
		}
		return 84;
	}
}

int main(int argc, char *argv[])
{
	int i = 2;
	int flag = 0;
	if(argc == 1)
	{
		my_puterrstr("Usage: grep [OPTION]... PATTERN [FILE]...\n");
		return 84;
	}
	if(argc == 2)
	{
		my_argc_two(argv[1]);
	}
	while(i < argc)
	{
		if(my_grep(argv[1],argv[i]) == 84)
			flag = 84;
		i++;
	}
	if(flag == 0)
		return 0;
	else
		return 84;
}
