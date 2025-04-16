/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** read_aircraft.c
*/

#include "my_radar.h"

// int handle_invalid_format(file_context_t *context)
// {
//     int iError = ERROR_FILE;

//     return(iError);
// }

int read_aircrafts(file_context_t *context, entities_params_t *params,
    texture_manager_t *texture_manager)
{
    int iError = NO_ERROR;
    int i = 0;

    params->aircrafts = malloc(sizeof(aircraft_t) * params->num_aircrafts);
    if (params->aircrafts == NULL)
        iError = ERROR_AIRCRAFT;
    while ((i < params->num_aircrafts) && (iError == NO_ERROR)) {
        if (getline(context->line, context->len, context->file) == -1)
            iError = ERROR_FILE;
        if ((iError == NO_ERROR) && (*(context->line)[0] == 'A')) {
            parse_aircraft_line(*(context->line), &(params->aircrafts)[i],
                texture_manager);
            i++;
        }
    }
    return (iError);
}

// int process_aircraft_line(file_context_t *context, aircraft_t *aircraft,
//     texture_manager_t *texture_manager)
// {
//     if (getline(context->line, context->len, context->file) == -1)
//         iError = ERROR_FILE;
//     if (*(context->line)[0] == 'A') {
//         parse_aircraft_line(*(context->line), &params->aircrafts[i],
//         texture_manager);
//         return (1);
//     }
//     return (0);
// }

// int read_aircrafts(file_context_t *context, aircraft_t *aircrafts,
//     int count_aircraft, texture_manager_t *texture_manager)
// {
//     int i = 0;

// //            params->aircrafts = malloc(sizeof(aircraft_t) *
//     params->num_aircrafts);
// // si null => error

//     while (i < count_aircraft)
//         i += process_aircraft_line(context, &aircrafts[i], texture_manager);
// }

// int process_aircraft_line(file_context_t *context, aircraft_t *aircraft)
// {
//     if (getline(context->line, context->len, context->file) == -1)
//         handle_invalid_format(context);
//     if (*(context->line)[0] == 'A') {
//         parse_aircraft_line(*(context->line), aircraft);
//         return (1);
//     }
//     return (0);
// }

// void read_aircrafts(file_context_t *context, aircraft_t *aircrafts,
//     int count_aircraft)
// {
//     int i = 0;

//     while (i < count_aircraft)
//         i += process_aircraft_line(context, &aircrafts[i]);
// }
