/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday10-leonard.leroy
** File description:
** my_isalnum.c
*/

#include "my.h"

int my_isalnum(char cVerif)
{
    if ((cVerif >= '0' && cVerif <= '9') || (cVerif >= 'A' && cVerif <= 'Z')
        || (cVerif >= 'a' && cVerif <= 'z')) {
        return (1);
    }
    return (0);
}
