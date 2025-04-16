/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-leonard.leroy
** File description:
** my.h
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_end_of_get_nbr(char const *str, int i, int nb_of_minus, int nb_of_plus);
int my_getnbr(char const *str);
//void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
//char *my_strstr(char *str, char const *to_find);
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
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
int my_isalnum(char cVerif);
int count_nbr_words(char const *str);
int count_nbr_alphanum_per_word(char const *str, int iPos);
int mini_printf(const char *format_string, ...);

#endif /* !MY_H_ */
