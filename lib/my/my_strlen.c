/*
** EPITECH PROJECT, 2024
** DAY04
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int cnt = 0;

    while (str[cnt] != '\0') {
        cnt++;
    }
    return (cnt);
}
