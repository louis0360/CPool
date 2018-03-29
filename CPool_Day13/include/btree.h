#ifndef BTREE_H
#define BTREE_H

#include <stddef.h>
typedef struct btree
{
	struct btree *left;
	struct btree *right;
	void *item;
} btree_t;

typedef struct rb_node
{
	struct rb_node *left;
	struct rb_node *right;
	void *data;
	enum RB_COLOR {RB_BLACK, RB_RED} color;
} rb_node_t;

btree_t *btree_create_node(void *item);
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
void btree_apply_infix(btree_t *root, int (*applyf)(void *));
void btree_apply_suffix(btree_t *root, int (*applyf)(void *));
void btree_insert_data(btree_t **root, void *item, int (*cmpf)());
void *btree_search_item(btree_t const *root, void const *data_ref, int (*cmpf)());
size_t btree_level_count(btree_t const *root);
void btree_apply_by_level(btree_t *root, void (*applyf)(void *item, int level, int is_first_elem));
void rb_insert(rb_node_t **root, void *data, int (*cmpf)());
void rb_remove(rb_node_t **root, void *data, int (*cmpf)(void *, void *), void (*f) (void *));


	void my_putchar(char c);
	int my_isneg(int nb);
	int my_put_nbr(int nb);
	void my_swap(int *a, int *b);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	int my_getnbr(char const *str);
	void my_sort_int_array(int *tab, int size);
	int my_compute_power_rec(int nb, int power);
	int my_compute_square_root(int nb);
	int my_is_prime(int nb);
	int my_find_prime_sup(int nb);
	char *my_strcpy(char *dest, char const *src);
	char *my_strncpy(char *dest, char const *src, int n);
	char *my_revstr(char *str);
	char *my_strstr(char *str, char const *to_find);
	int my_strcmp(char const *s1, char const *s2);
	int my_strncmp(char const *s1, char const *s2, int n);
	char *my_strupcase(char *str);
	char *my_strlowcase(char *str);
	char *my_strcapitalize(char *str);
	int my_str_isalpha(char const *str);
	int my_str_isnum(char const *str);
	int my_str_islower(char const *str);
	int my_str_isupper(char const *str);
	int my_str_isprintable(char const *str);
	int my_showstr(char const *str);
	int my_showmem(char const *str, int size);
	char *my_strcat(char *dest, char const *src);
	char *my_strncat(char *dest, char const *src, int nb);
	char *my_strdup(char const *src);
	char *concat_params(int argc, char **argv);
	int my_show_word_array(char * const *tab);
	char **my_str_to_word_array(char const *str);
	char *convert_base(char const *nbr, char const *base_from, char const *base_to);
#endif
