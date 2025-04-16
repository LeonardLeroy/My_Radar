/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday06-nadal.berthelon
** File description:
** my_strupcase.c
*/
#include "my.h"
char *my_strupcase(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 97 && str[i] <= 122){
            str[i] = (str[i] - 32);
        }
    }
    return str;
}
