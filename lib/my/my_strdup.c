/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday09-leonard.leroy
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int strlength = my_strlen(src);
    char *ptrResult = malloc(sizeof(char) * (strlength + 1));

    ptrResult = my_strcpy(ptrResult, src);
    ptrResult[strlength] = '\0';
    return ptrResult;
}
