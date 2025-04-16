/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int length1 = my_strlen(s1);
    int length2 = my_strlen(s2);

    if (length1 < length2) {
        return (-1);
    }
    if (length1 > length2) {
        return (1);
    }
    for (int i = 0; i < length1; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
