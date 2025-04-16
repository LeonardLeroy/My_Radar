/*
** EPITECH PROJECT, 2024
** DAY07
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int x = my_strlen(dest);
    int y = 0;

    while (src[y] != '\0') {
        dest[x + y] = src[y];
        y++;
    }
    dest[x + y] = '\0';
    return dest;
}
