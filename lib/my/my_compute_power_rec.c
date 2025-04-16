/*
** EPITECH PROJECT, 2024
** DAY05
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int resultat = nb;

    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    }
    return my_compute_power_rec(nb, p - 1) * nb;
}
