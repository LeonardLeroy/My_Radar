/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** script_loader.c
*/

#include "my_radar.h"

// void load_entities_from_script(const char *filepath,
//        entities_params_t *params)
// {
//     FILE *file = fopen(filepath, "r");
//     char *line = NULL;
//     size_t len = 0;
//     int count_aircraft = 0;
//     int count_towers = 0;
//     file_context_t context = {file, &line, &len};

//     if (!file) {
//         my_putstr("Failed to open script file: ");
//         my_putstr(filepath);
//         my_putstr("\n");
//         exit(84);
//     }
//     read_entity_counts(&context, &count_aircraft, &count_towers);
//     initialize_entities(&context, params, count_aircraft, count_towers);
//     free(line);
//     fclose(file);
// }

// void load_entities_from_script(const char *filepath,
//       entities_params_t *params)
// {
//     FILE *file = fopen(filepath, "r");
//     char *line = NULL;
//     size_t len = 0;
//     int count_aircraft = 0;
//     int count_towers = 0;
//     file_context_t context = {file, &line, &len};

//     if (!file) {
//         my_putstr("Failed to open script file: ");
//         my_putstr(filepath);
//         my_putstr("\n");
//         exit(84);
//     }
//     while (getline(&line, &len, file) != -1) {
//         if (line[0] == 'A')
//             count_aircraft++;
//         if (line[0] == 'T')
//             count_towers++;
//     }
//     fseek(file, 0, SEEK_SET);
//     initialize_entities(&context, params, count_aircraft, count_towers);
//     free(line);
//     fclose(file);
// }

// void load_entities_from_script(const char *filepath,
//      entities_params_t *params)
// {
//     FILE *file = fopen(filepath, "r");
//     char *line = NULL;
//     size_t len = 0;
//     int count_aircraft = 0;
//     int count_towers = 0;
//     file_context_t context = {file, &line, &len};

//     if (!file) {
//         my_putstr("Failed to open script file: ");
//         my_putstr(filepath);
//         my_putstr("\n");
//         exit(84);
//     }
//     while (getline(&line, &len, file) != -1) {
//         if (line[0] == 'A')
//             count_aircraft++;
//         else if (line[0] == 'T')
//             count_towers++;
//     }
//     fseek(file, 0, SEEK_SET);
//     initialize_entities(&context, params, count_aircraft, count_towers);
//     free(line);
//     fclose(file);
// }

// void handle_file_error(const char *filepath)
// {
//     my_putstr("Failed to open script file: ");
//     my_putstr(filepath);
//     my_putstr("\n");
//     exit(84);
// }

void increment_entity_count(char type, int *count_aircraft, int *count_towers)
{
    if (type == 'A')
        (*count_aircraft)++;
    else if (type == 'T')
        (*count_towers)++;
}

int count_entities(const char *filepath, entities_params_t *params)
{
    int iError = NO_ERROR;
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        iError = ERROR_FILE;
    if (iError == NO_ERROR) {
        while (getline(&line, &len, file) != -1)
            increment_entity_count(line[0], &(params->num_aircrafts),
                &(params->num_towers));
        free(line);
        fclose(file);
    }
    return (iError);
}

int initialize_entities(const char *filepath, entities_params_t *params,
    texture_manager_t *texture_manager)
{
    int iError = NO_ERROR;
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    file_context_t context = {file, &line, &len};

    if (file == NULL)
        iError = ERROR_FILE;
    if (iError == NO_ERROR)
        iError = read_aircrafts(&context, params, texture_manager);
    if (iError == NO_ERROR)
        iError = read_towers(&context, params, texture_manager);
    if (file != NULL)
        fclose(file);
    return (iError);
}

// int initialize_entities(const char *filepath, entities_params_t *params,
//     texture_manager_t *texture_manager)
// {
//     int iError = NO_ERROR;
//     FILE *file = fopen(filepath, "r");
//     char *line = NULL;
//     size_t len = 0;
//     file_context_t context = {file, &line, &len};

//     if (file == NULL)
//         iError = 84;
//     if (iError == NO_ERROR) {
// //        params->aircrafts = malloc(sizeof(aircraft_t) *
//         params->num_aircrafts);
//         params->towers = malloc(sizeof(control_tower_t) *
//          params->num_towers);
//  //       if ((params->aircrafts == NULL) || (params->towers == NULL))
//  //           iError = 84;
//     }
//     if (iError == NO_ERROR) {
// //        read_aircrafts(&context, params->aircrafts, params->num_aircrafts,
//        texture_manager);
//         read_aircrafts(&context, params, texture_manager);
//         read_towers(&context, params->towers, params->num_towers,
//        texture_manager);
//     }
//     if (file != NULL)
//         fclose(file);
//     return (iError);
// }

// void read_entity_counts(file_context_t *context, int *count_aircraft,
//     int *count_towers)
// {
//     char **words;

//     if (getline(context->line, context->len, context->file) != -1) {
//         words = my_str_to_word_array(*(context->line));
//         *count_aircraft = my_getnbr(words[0]);
//         *count_towers = my_getnbr(words[1]);
//     } else {
//         my_putstr("Invalid script file format\n");
//         fclose(context->file);
//         exit(84);
//     }
// }

// void read_aircrafts(file_context_t *context, aircraft_t *aircrafts,
//     int count_aircraft)
// {
//     int i;

//     for (i = 0; i < count_aircraft; i++) {
//         if (getline(context->line, context->len, context->file) != -1) {
//             if (*(context->line)[0] == 'A') {
//                 parse_aircraft_line(*(context->line), &aircrafts[i]);
//             } else {
//                 i--;
//             }
//         } else {
//             my_putstr("Invalid script file format\n");
//             fclose(context->file);
//             exit(84);
//         }
//     }
// }

// void read_towers(file_context_t *context, control_tower_t *towers,
//     int count_towers)
// {
//     int i;

//     for (i = 0; i < count_towers; i++) {
//         if (getline(context->line, context->len, context->file) != -1) {
//             if (*(context->line)[0] == 'T') {
//                 parse_tower_line(*(context->line), &towers[i]);
//             } else {
//                 i--;
//             }
//         } else {
//             my_putstr("Invalid script file format\n");
//             fclose(context->file);
//             exit(84);
//         }
//     }
// }
