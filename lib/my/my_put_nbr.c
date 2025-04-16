/*
** EPITECH PROJECT, 2024
** DAY03
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int iNbCar = 0;
    long nbr = nb;

    if (nbr < 0) {
        my_putchar('-');
        iNbCar++;
        nbr *= -1;
    }
    if (nbr > 9) {
        iNbCar += my_put_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + '0');
    iNbCar++;
    return (iNbCar);
}
