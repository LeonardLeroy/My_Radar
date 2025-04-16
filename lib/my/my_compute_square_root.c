/*
** EPITECH PROJECT, 2024
** DAY05
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int square = 0;
    int i = 0;

    while (square < nb) {
        square = i * i;
        if (square == nb) {
            return i;
        }
        i++;
    }
    return 0;
}
