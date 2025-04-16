/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** my_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int x = 0;
    int y = my_strlen(str) - 1;
    char temp;

    while (x < y) {
        temp = str[x];
        str[x] = str[y];
        str[y] = temp;
        x++;
        y--;
    }
    return str;
}
