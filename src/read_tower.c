/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** read_tower.c
*/

#include "my_radar.h"

// int parse_line(file_context_t *context, control_tower_t *towers, int i)
// {
//     if (getline(context->line, context->len, context->file) == -1)
//         handle_invalid_format(context);
//     if (*(context->line)[0] == 'T') {
//         parse_tower_line(*(context->line), &towers[i]);
//         return (1);
//     }
//     return (0);
// }

// void read_towers(file_context_t *context, control_tower_t *towers,
//     int count_towers)
// {
//     int i = 0;

//     while (i < count_towers)
//         i += parse_line(context, towers, i);
// }

// int parse_line(file_context_t *context, control_tower_t *towers, int i,
//     texture_manager_t *texture_manager)
// {
//     if (getline(context->line, context->len, context->file) == -1)
//         handle_invalid_format(context);
//     if (*(context->line)[0] == 'T') {
//         parse_tower_line(*(context->line), &towers[i], texture_manager);
//         return (1);
//     }
//     return (0);
// }

int read_towers(file_context_t *context, entities_params_t *params,
    texture_manager_t *texture_manager)
{
    int iError = NO_ERROR;
    int i = 0;

    params->towers = malloc(sizeof(control_tower_t) * params->num_towers);
    if (params->towers == NULL)
        iError = ERROR_TOWER;
    while ((i < params->num_towers) && (iError == NO_ERROR)) {
        if (getline(context->line, context->len, context->file) == -1)
            iError = ERROR_FILE;
        if ((iError == NO_ERROR) && (*(context->line)[0] == 'T')) {
            parse_tower_line(*(context->line), &(params->towers)[i],
                texture_manager);
            i++;
        }
    }
    return (iError);
}

// void read_towers(file_context_t *context, control_tower_t *towers,
//     int count_towers, texture_manager_t *texture_manager)
// {
//     int i = 0;

//     while (i < count_towers)
//         i += parse_line(context, towers, i, texture_manager);
// }
