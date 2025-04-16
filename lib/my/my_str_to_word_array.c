/*
** EPITECH PROJECT, 2024
** B-CPE-100-LYN-1-1-cpoolday09-leonard.leroy
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include <stdlib.h>

char **my_str_to_word_array(char const *str)
{
    int iNbWords = count_nbr_words(str);
    char **ptrPtrResult = malloc(sizeof(char *) * (iNbWords + 1));
    int iLengthWord = 0;
    int iCursorW = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        iLengthWord = count_nbr_alphanum_per_word(str, i);
        if (iLengthWord != 0) {
            ptrPtrResult[iCursorW] = malloc(sizeof(char) * (iLengthWord) + 1);
            my_strncpy(ptrPtrResult[iCursorW], str + i, iLengthWord);
            iCursorW++;
        }
        i = i + iLengthWord;
    }
    ptrPtrResult[iCursorW] = NULL;
    return ptrPtrResult;
}
