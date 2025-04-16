/*
** EPITECH PROJECT, 2024
** DAY05
** File description:
** my_compute_square_root
*/

int my_is_prime(int nb)
{
    int iNbPositif = nb;

    if (nb < 0) {
        iNbPositif = nb * (-1);
    }
    if ((iNbPositif == 0) || (iNbPositif == 1)) {
        return 0;
    }
    for (int i = 2; i < iNbPositif; i++) {
        if ((iNbPositif % i) == 0) {
            return 0;
        }
    }
    return 1;
}
