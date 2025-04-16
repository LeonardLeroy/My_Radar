/*
** EPITECH PROJECT, 2024
** DAY05
** File description:
** my_compute_power_rec
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
