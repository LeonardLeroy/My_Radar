/*
** EPITECH PROJECT, 2024
** DAY07
** File description:
** my_strcat
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    if ((my_str_islower(str) == 1) || (my_str_isupper(str) == 1)) {
        return (1);
    }
    return (0);
}
