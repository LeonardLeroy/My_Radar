/*
** EPITECH PROJECT, 2024
** DAY07
** File description:
** my_strcat
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int iLength = my_strlen(str);
    int iRetour = 1;

    for (int i = 0; i < iLength; i++) {
        if ((str[i] == '\0') || (str[i] == '\a') || (str[i] == '\b')
        || (str[i] == '\f') || (str[i] == '\n') || (str[i] == '\r')
        || (str[i] == '\t') || (str[i] == '\v')) {
            iRetour = 0;
        }
    }
    return (iRetour);
}
