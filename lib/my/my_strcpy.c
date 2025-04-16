/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int x = 0;

    while (src[x] != '\0') {
        dest[x] = src[x];
        x++;
    }
    dest[x] = '\0';
    return dest;
}
