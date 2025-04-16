/*
** EPITECH PROJECT, 2024
** DAY04
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int nbr = 0;

    while (str[nbr] != '\0') {
        my_putchar(str[nbr]);
        nbr++;
    }
    return (nbr);
}
