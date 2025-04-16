/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** load_entities_from_file.c
*/

#include "my_radar.h"

int load_entities_from_script(const char *filepath, entities_params_t *params,
    texture_manager_t *texture_manager)
{
    int iError = NO_ERROR;

    if (iError == NO_ERROR)
        iError = count_entities(filepath, params);
    if (iError == NO_ERROR)
        iError = initialize_entities(filepath, params, texture_manager);
    return (iError);
}
