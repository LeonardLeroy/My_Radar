/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-countisland-leonard.leroy
** File description:
** my_show_word_array.c
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    int iCount = 0;

    while (tab[iCount] != 0) {
        my_putstr(tab[iCount]);
        my_putchar('\n');
        iCount++;
    }
    return (0);
}
