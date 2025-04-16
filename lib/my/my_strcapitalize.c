/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-nadal.berthelon
** File description:
** my_strcapitalize.c
*/
#include "my.h"

char *my_strupchar(char *str, int i)
{
    if (i == 0) {
        str[i] = (str[i] - 32);
    }
    if (str[i] >= 97 && str[i] <= 122 && (str[i - 1] < 65 || str[i - 1] > 90)){
            str[i] = (str[i] - 32);
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    my_strlowcase(str);
    my_strupchar(str, 0);
    for (int i = 1; i < len; i++) {
        if ((str[i] < 97 || str[i] > 122) && (str[i] < 48 || str[i] > 57)) {
            my_strupchar(str, (i + 1));
        }
    }
    return str;
}
