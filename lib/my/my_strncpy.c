/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = my_strlen(src);
    int x = 0;

    for (; x < n; x++) {
        if (x < length) {
            dest[x] = src[x];
        } else {
            dest[x] = '\0';
        }
    }
    dest[x] = '\0';
    return dest;
}
