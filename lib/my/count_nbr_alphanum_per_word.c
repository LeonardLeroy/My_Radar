/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday10-leonard.leroy
** File description:
** count_nbr_alphanum_per_word.c
*/

#include "my.h"

int count_nbr_alphanum_per_word(char const *str, int iPos)
{
    int iNbRetour = iPos;

    while (my_isalnum(str[iNbRetour]) == 1) {
        iNbRetour++;
    }
    return (iNbRetour - iPos);
}
