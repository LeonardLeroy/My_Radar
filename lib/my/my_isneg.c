/*
** EPITECH PROJECT, 2024
** DAY03
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else if (n >= 0) {
        my_putchar(80);
    }
    return (0);
}
