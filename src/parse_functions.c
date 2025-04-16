/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** parse_functions.c
*/

#include "my_radar.h"

// void parse_aircraft_line(char *line, aircraft_t *aircraft)
// {
//     char **words = my_str_to_word_array(line);
//     float x_depart = strtof(words[1], NULL);
//     float y_depart = strtof(words[2], NULL);
//     float x_arrivee = strtof(words[3], NULL);
//     float y_arrivee = strtof(words[4], NULL);
//     float speed = strtof(words[5], NULL);
//     float delay = strtof(words[6], NULL);

//     *aircraft =
//         *create_aircraft((sfVector2f){x_depart, y_depart},
//             (sfVector2f){x_arrivee, y_arrivee}, speed, delay);
// }

// void parse_tower_line(char *line, control_tower_t *tower)
// {
//     char **words = my_str_to_word_array(line);
//     float x_position = strtof(words[1], NULL);
//     float y_position = strtof(words[2], NULL);
//     float radius = strtof(words[3], NULL);

//     *tower =
//         *create_control_tower((sfVector2f){x_position, y_position}, radius);
// }

void parse_aircraft_line(char *line, aircraft_t *aircraft,
    texture_manager_t *texture_manager)
{
    char **words = my_str_to_word_array(line);
    float x_depart = my_atof_combined(words[1]);
    float y_depart = my_atof_combined(words[2]);
    float x_arrivee = my_atof_combined(words[3]);
    float y_arrivee = my_atof_combined(words[4]);
    float speed = my_atof_combined(words[5]);
    float delay = my_atof_combined(words[6]);
    float speeddelay[2] = {speed, delay};

    *aircraft = *create_aircraft((sfVector2f){x_depart, y_depart},
        (sfVector2f){x_arrivee, y_arrivee}, speeddelay, texture_manager);
}

void parse_tower_line(char *line, control_tower_t *tower,
    texture_manager_t *texture_manager)
{
    char **words = my_str_to_word_array(line);
    float x_position = my_atof_combined(words[1]);
    float y_position = my_atof_combined(words[2]);
    float radius = my_atof_combined(words[3]);

    *tower = *create_control_tower((sfVector2f){x_position, y_position},
        radius, texture_manager);
}

float my_atof_combined(const char *str)
{
    int integer_part = my_getnbr(str);
    float decimal_part = get_decimal_part(str);

    if (integer_part < 0)
        return (integer_part - decimal_part);
    return (integer_part + decimal_part);
}

// void parse_aircraft_line(char *line, aircraft_t *aircraft)
// {
//     char **words = my_str_to_word_array(line);
//     float x_depart = atof(words[1]);
//     float y_depart = atof(words[2]);
//     float x_arrivee = atof(words[3]);
//     float y_arrivee = atof(words[4]);
//     float speed = atof(words[5]);
//     float delay = atof(words[6]);

//     *aircraft = *create_aircraft((sfVector2f){x_depart, y_depart},
//         (sfVector2f){x_arrivee, y_arrivee}, speed, delay);
// }

// void parse_tower_line(char *line, control_tower_t *tower)
// {
//     char **words = my_str_to_word_array(line);
//     float x_position = atof(words[1]);
//     float y_position = atof(words[2]);
//     float radius = atof(words[3]);

//     *tower =
//         *create_control_tower((sfVector2f){x_position, y_position}, radius);
// }

// void parse_tower_line(char *line, control_tower_t *tower)
// {
//     char **words = my_str_to_word_array(line);
//     float x_position = my_getnbr(words[1]);
//     float y_position = my_getnbr(words[2]);
//     float radius = my_getnbr(words[3]);

//     *tower =
//         *create_control_tower((sfVector2f){x_position, y_position}, radius);
// }
