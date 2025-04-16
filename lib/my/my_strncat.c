/*
** EPITECH PROJECT, 2024
** DAY07
** File description:
** my_strcat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int x = my_strlen(dest);
    int y = 0;

    while (src[y] != '\0' && y < nb) {
        dest[x + y] = src[y];
        y++;
    }
    dest[x + y] = '\0';
    return dest;
}
