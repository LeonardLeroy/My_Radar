/*
** EPITECH PROJECT, 2024
** DAY04
** File description:
** my_getnbr
*/

int my_end_of_get_nbr(char const *str, int i, int nb_of_minus, int nb_of_plus)
{
    long long result = 0;
    int imax = 2147483647;
    int imin = -2147483648;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (nb_of_minus > nb_of_plus) {
        result *= -1;
    }
    if ((result > imax) || (result < imin)) {
        return (0);
    } else {
        return (result);
    }
}

int my_getnbr(char const *str)
{
    int num = 0;
    int i = 0;
    int nb_of_minus = 0;
    int nb_of_plus = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            nb_of_minus++;
        } else {
            nb_of_plus++;
        }
        i++;
    }
    num = my_end_of_get_nbr(str, i, nb_of_minus, nb_of_plus);
    return (num);
}

float get_decimal_part(const char *str)
{
    float decimal_part = 0.0;
    float decimal_place = 0.1;
    int i = 0;

    while ((str[i]) && (str[i] != '.'))
        i++;
    if (str[i] != '.')
        return (decimal_part);
    i++;
    while (str[i]) {
        if ((str[i] >= '0') && (str[i] <= '9')) {
            decimal_part += (str[i] - '0') * decimal_place;
            decimal_place *= 0.1;
        }
        i++;
    }
    return (decimal_part);
}
