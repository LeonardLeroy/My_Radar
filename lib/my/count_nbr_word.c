/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday10-leonard.leroy
** File description:
** count_nbr_word.c
*/

#include "my.h"

int count_nbr_words(char const *str)
{
    int i = 1;
    int iNbWord = 0;

    while (i <= my_strlen(str)) {
        if ((my_isalnum(str[i]) != 1) && (my_isalnum(str[i - 1]) == 1)){
            iNbWord++;
        }
        i++;
    }
    return (iNbWord);
}
