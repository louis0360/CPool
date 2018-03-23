#include <stdlib.h>
#include "./include/my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
	int i;
	struct info_param *av_info;
	av_info = malloc(sizeof(struct info_param) * (ac+1));
	for(i = 0; i < ac; i++)
	{
		av_info[i].length = my_strlen(av[i]);
		av_info[i].str = av[i];
		av_info[i].copy = my_strdup(av[i]);
		av_info[i].word_array = my_str_to_word_array(av[i]);
	}
	return av_info;
}
