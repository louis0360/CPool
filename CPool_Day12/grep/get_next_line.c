#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"

#define READ_MAX 5

char *my_realloc(char *old, int size)
{
	int i;
	char *new;

	i = 0;
	if ((new = malloc(sizeof(*new) * (my_strlen(old) + size))) == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

char *get_next_line(const int fd)
{
	static int last = 1;
	static int rd = 0;
	static int i = 0;
	static char *rs = NULL;
	static char buf[READ_MAX];

	if (buf[my_strlen(buf) - rd] == '\0')
	{
		if ((rd = read(fd, buf, READ_MAX)) <= 0)
			return (rs = (last-- && buf[my_strlen(buf) - rd - 1] != 10) ? rs : NULL);
		buf[rd] = '\0';
	}
	if ((rs = (i == 0) ? malloc(sizeof(*rs) * READ_MAX + 1) :
		my_realloc(rs, sizeof(*rs) * READ_MAX + 1)) == NULL)
	return (NULL);
	while (buf[my_strlen(buf) - rd] && buf[my_strlen(buf) - rd] != '\n')
		rs[i++] = buf[my_strlen(buf) - rd--];
	rs[i] = '\0';
	if (buf[my_strlen(buf) - rd] == '\n')
	{
		i = 0;
		rd--;
		return (rs);
	}
	return (get_next_line(fd));
}
