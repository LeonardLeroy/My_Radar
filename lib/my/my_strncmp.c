/*
** EPITECH PROJECT, 2024
** DAY06
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return ((s1[i] - s2[i]));
        }
        if ((s1[i] == '\0') || (s2[i] == '\0')) {
            return (0);
        }
    }
    return (0);
}
