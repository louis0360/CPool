#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "../include/my.h"

int my_argc_one(void)
{
	char buffer[32];
	int size = 1;

	while (size > 0) 
	{
		for (int i = 0; i < 32; ++i)
			buffer[i] = '\0';
		size = read(0, buffer, 31);
		if(size == -1)
			return -1;
		my_putstr(buffer);
	}
	return 0;
}

int my_puterrstr(char const *str)
{
	return write(2,str,my_strlen(str));
}

int my_cat(char const *file)
{
	int fd,n;
	char buf[32];
	fd = open(file,O_RDONLY);
	if (fd != -1)
	{
		for(int i = 0; i < 32; ++i)
			buf[i]='\0';
		n=read(fd,buf,31);
		if (n!=-1&&n!=0)
		{
			while (n>0)
			{
				write(1,buf,n);
				n=read(fd,buf,31);
			}
		}
		else
		{
			my_puterrstr("cat: ");
			my_puterrstr(file);
			my_puterrstr(": Is a directory\n");
			return 84;
		}
		close(fd);
		return 0;
	}
	else
	{
		if(errno == 2)
		{
			my_puterrstr("cat: ");
			my_puterrstr(file);
			my_puterrstr(": No such file or directory\n");
		}
		if(errno == 13)
		{
			my_puterrstr("cat: ");
			my_puterrstr(file);
			my_puterrstr(": Permission denied\n");
		}
		return 84;
	}
}

int main(int argc, char *argv[])
{
	int i = 1;
	int flag = 0;
	if(argc == 1)
		my_argc_one();
	while(i < argc)
	{	
		if(my_cat(argv[i]) == 84)
			flag = 84;
		i++;
	}
	if(flag == 0)
		return 0;
	else
		return 84;
}
