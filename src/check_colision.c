/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** check_colision.c
*/

#include "my_radar.h"

// void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
//     collision_params_t *params)
// {
//     sfTime current_time =
//          sfClock_getElapsedTime(aircraft1->aircraft->clock);

//     if ((sfTime_asSeconds(current_time) < aircraft1->aircraft->delay)
//         || (aircraft1->aircraft->speed == 0))
//         return;
//     current_time = sfClock_getElapsedTime(aircraft2->aircraft->clock);
//     if ((sfTime_asSeconds(current_time) < aircraft2->aircraft->delay)
//         || (aircraft2->aircraft->speed == 0))
//         return;
//     sfVector2f pos1 =
//        sfRectangleShape_getPosition(aircraft1->aircraft->shape);
//     sfVector2f pos2 =
//      sfRectangleShape_getPosition(aircraft2->aircraft->shape);
//     if (((pos1.x == aircraft1->aircraft->arrival.x)
//          && (pos1.y == aircraft1->aircraft->arrival.y))
//         || ((pos2.x == aircraft2->aircraft->arrival.x)
//             && (pos2.y == aircraft2->aircraft->arrival.y)))
//         return;
//     if (is_intersecting_aircrafts(aircraft1->aircraft,
//            aircraft2->aircraft)) {
//         check_and_handle_collision(aircraft1->aircraft,
//             aircraft2->aircraft);
//     }
// }

// void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
//     collision_params_t *params, control_tower_t *tower)
// {
//     sfTime current_time =
//           sfClock_getElapsedTime(aircraft1->aircraft->clock);

//     if ((sfTime_asSeconds(current_time) < aircraft1->aircraft->delay)
//         || (aircraft1->aircraft->speed == 0))
//         return;
//     current_time = sfClock_getElapsedTime(aircraft2->aircraft->clock);
//     if ((sfTime_asSeconds(current_time) < aircraft2->aircraft->delay)
//         || (aircraft2->aircraft->speed == 0))
//         return;
//     sfVector2f pos1 =
//           sfRectangleShape_getPosition(aircraft1->aircraft->shape);
//     sfVector2f pos2 =
//         sfRectangleShape_getPosition(aircraft2->aircraft->shape);
//     if (((pos1.x == aircraft1->aircraft->arrival.x)
//         && (pos1.y == aircraft1->aircraft->arrival.y))
//         || ((pos2.x == aircraft2->aircraft->arrival.x)
//             && (pos2.y == aircraft2->aircraft->arrival.y)))
//         return;
//     check_and_handle_collision(aircraft1->aircraft, aircraft2->aircraft,
//         tower);
// }

// void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
//     collision_params_t *params, control_tower_t *tower)
// {
//     sfTime current_time;
//     sfVector2f pos1;
//     sfVector2f pos2;

//     current_time = sfClock_getElapsedTime(aircraft1->aircraft->clock);
//     if ((sfTime_asSeconds(current_time) < aircraft1->aircraft->delay)
//         || (aircraft1->aircraft->speed == 0))
//         return;
//     current_time = sfClock_getElapsedTime(aircraft2->aircraft->clock);
//     if ((sfTime_asSeconds(current_time) < aircraft2->aircraft->delay)
//         || (aircraft2->aircraft->speed == 0))
//         return;
//     pos1 = sfRectangleShape_getPosition(aircraft1->aircraft->shape);
//     pos2 = sfRectangleShape_getPosition(aircraft2->aircraft->shape);
//     if (((pos1.x == aircraft1->aircraft->arrival.x)
//         && (pos1.y == aircraft1->aircraft->arrival.y))
//         || ((pos2.x == aircraft2->aircraft->arrival.x)
//             && (pos2.y == aircraft2->aircraft->arrival.y)))
//         return;
//     check_and_handle_collision(aircraft1->aircraft, aircraft2->aircraft,
//     tower);
// }

// void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
//     control_tower_t *tower)
// {
//     sfTime current_time =
//         sfClock_getElapsedTime(aircraft1->aircraft->clock);
//     sfVector2f pos1;
//     sfVector2f pos2;

//     if ((sfTime_asSeconds(current_time) < aircraft1->aircraft->delay)
//         || (aircraft1->aircraft->speed == 0))
//         return;
//     current_time = sfClock_getElapsedTime(aircraft2->aircraft->clock);
//     if ((sfTime_asSeconds(current_time) < aircraft2->aircraft->delay)
//         || (aircraft2->aircraft->speed == 0))
//         return;
//     pos1 = sfRectangleShape_getPosition(aircraft1->aircraft->shape);
//     pos2 = sfRectangleShape_getPosition(aircraft2->aircraft->shape);
//     if (((pos1.x == aircraft1->aircraft->arrival.x)
//         && (pos1.y == aircraft1->aircraft->arrival.y))
//         || ((pos2.x == aircraft2->aircraft->arrival.x)
//             && (pos2.y == aircraft2->aircraft->arrival.y)))
//         return;
//     check_and_handle_collision(aircraft1->aircraft, aircraft2->aircraft,
//     tower);
// }

int check_in_control_area(aircraft_t *aircraft1, aircraft_t *aircraft2,
    collision_params_t *params)
{
    int i;

    for (i = 0; i < params->num_towers; i++) {
        if ((is_in_control_area(aircraft1, &params->towers[i]))
            || (is_in_control_area(aircraft2, &params->towers[i])))
            return (1);
    }
    return (0);
}

void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
    control_tower_t *towers, int num_towers)
{
    sfTime current_time = sfClock_getElapsedTime(aircraft1->aircraft->clock);
    sfVector2f pos1;
    sfVector2f pos2;

    if ((sfTime_asSeconds(current_time) < aircraft1->aircraft->delay)
        || (aircraft1->aircraft->speed == 0))
        return;
    current_time = sfClock_getElapsedTime(aircraft2->aircraft->clock);
    if ((sfTime_asSeconds(current_time) < aircraft2->aircraft->delay)
        || (aircraft2->aircraft->speed == 0))
        return;
    pos1 = sfRectangleShape_getPosition(aircraft1->aircraft->shape);
    pos2 = sfRectangleShape_getPosition(aircraft2->aircraft->shape);
    if (((pos1.x == aircraft1->aircraft->arrival.x)
        && (pos1.y == aircraft1->aircraft->arrival.y))
        || ((pos2.x == aircraft2->aircraft->arrival.x)
            && (pos2.y == aircraft2->aircraft->arrival.y)))
        return;
    check_and_handle_collision(aircraft1->aircraft, aircraft2->aircraft,
        towers, num_towers);
}

void process_section_collisions(collision_params_t *params, int row, int col)
{
    aircraft_node_t *aircraft1;
    aircraft_node_t *aircraft2;

    aircraft1 = params->sections[row][col].aircrafts;
    while (aircraft1) {
        aircraft2 = aircraft1->next;
        while (aircraft2) {
            check_collision(aircraft1, aircraft2, params->towers,
                params->num_towers);
            aircraft2 = aircraft2->next;
        }
        aircraft1 = aircraft1->next;
    }
}

void handle_aircraft_collisions(collision_params_t *params)
{
    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLS; col++) {
            process_section_collisions(params, row, col);
        }
    }
}

void process_collisions(section_t **sections, control_tower_t *towers,
    int num_towers)
{
    collision_params_t params = {sections, towers, num_towers};

    handle_aircraft_collisions(&params);
}

// void process_section_collisions(collision_params_t *params,
//         int row, int col,
//     control_tower_t *tower)
// {
//     aircraft_node_t *aircraft1;
//     aircraft_node_t *aircraft2;

//     aircraft1 = params->sections[row][col].aircrafts;
//     while (aircraft1) {
//         aircraft2 = aircraft1->next;
//         while (aircraft2) {
//             check_collision(aircraft1, aircraft2, tower);
//             aircraft2 = aircraft2->next;
//         }
//         aircraft1 = aircraft1->next;
//     }
// }

// void handle_aircraft_collisions(collision_params_t *params,
//     control_tower_t *tower)
// {
//     for (int row = 0; row < GRID_ROWS; row++) {
//         for (int col = 0; col < GRID_COLS; col++) {
//             process_section_collisions(params, row, col, tower);
//         }
//     }
// }

// void process_collisions(section_t **sections, control_tower_t *towers,
//     int num_towers, control_tower_t *tower)
// {
//     collision_params_t params = {sections, towers, num_towers};

//     handle_aircraft_collisions(&params, tower);
// }

// void check_collision(aircraft_node_t *aircraft1,
//           aircraft_node_t *aircraft2,
//     collision_params_t *params)
// {
//     int in_control_area;

//     if (!is_intersecting_aircrafts(aircraft1->aircraft,
//            aircraft2->aircraft)) {
//         return;
//     }
//     in_control_area = check_in_control_area(aircraft1->aircraft,
//         aircraft2->aircraft, params);
//     if (!in_control_area) {
//         check_and_handle_collision(aircraft1->aircraft,
//             aircraft2->aircraft);
//     }
// }
