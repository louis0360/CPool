#ifndef OPP_H
#define OPP_H

struct operator
{
  char *opp;
  int (*fct)(char*, char*);
};

int my_add(char *nb1, char *nb2);
int my_sub(char *nb1, char *nb2);
int my_mul(char *nb1, char *nb2);
int my_div(char *nb1, char *nb2);
int my_mod(char *nb1, char *nb2);
int my_usage(char *nb1, char *nb2);

#endif
