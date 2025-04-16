/*
** EPITECH PROJECT, 2024
** DAY04
** File description:
** my_swap
*/

int my_swap(int *x, int *y)
{
    int swapy = *x;

    *x = *y;
    *y = swapy;
}
