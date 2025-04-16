/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** aicraft_collision.c
*/

#include "my_radar.h"

// int is_intersecting_aircrafts(aircraft_t *a1, aircraft_t *a2)
// {
//     sfVector2f pos1 = sfRectangleShape_getPosition(a1->shape);
//     sfVector2f pos2 = sfRectangleShape_getPosition(a2->shape);
//     float distX = pos1.x - pos2.x;
//     float distY = pos1.y - pos2.y;
//     float distance = sqrt(distX * distX + distY * distY);

//     return (distance <= 20);
// }

// void check_and_handle_collision(aircraft_t *aircraft1,
//      aircraft_t *aircraft2)
// {
//     if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
//         sfRectangleShape_setFillColor(aircraft1->shape, sfWhite);
//         sfRectangleShape_setFillColor(aircraft2->shape, sfWhite);
//         aircraft1->speed = 0;
//         aircraft2->speed = 0;
//     }
// }

// void handle_aircraft_collisions(section_t **sections, int row, int col)
// {
//     aircraft_node_t *node1 = sections[row][col].aircrafts;
//     aircraft_node_t *node2;

//     while (node1 != NULL) {
//         node2 = node1->next;
//         while (node2 != NULL) {
//             check_and_handle_collision(node1->aircraft, node2->aircraft);
//             node2 = node2->next;
//         }
//         node1 = node1->next;
//     }
// }

// void check_and_handle_collision(aircraft_t *aircraft1,
//        aircraft_t *aircraft2)
// {
//     if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
//         sfRectangleShape_setFillColor(aircraft1->shape, sfWhite);
//         sfRectangleShape_setFillColor(aircraft2->shape, sfWhite);
//         aircraft1->speed = 0;
//         aircraft2->speed = 0;
//     }
// }

// void check_and_handle_collision(aircraft_t *aircraft1,
//      aircraft_t *aircraft2,
//     control_tower_t *tower)
// {
//     if ((aircraft1->speed == 0) || (aircraft2->speed == 0))
//         return;
//     if ((is_in_control_area(aircraft1, tower))
//         && (is_in_control_area(aircraft2, tower)))
//         return;
//     if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
//         aircraft1->speed = 0;
//         aircraft2->speed = 0;
//     }
// }

// int is_intersecting_aircrafts(aircraft_t *a1, aircraft_t *a2)
// {
//     sfVector2f pos1 = sfRectangleShape_getPosition(a1->shape);
//     sfVector2f pos2 = sfRectangleShape_getPosition(a2->shape);
//     float distX = pos1.x - pos2.x;
//     float distY = pos1.y - pos2.y;
//     float distance = sqrt(distX * distX + distY * distY);

//     return (distance <= 20);
// }

// void check_and_handle_collision(aircraft_t *aircraft1,
//     aircraft_t *aircraft2, control_tower_t *towers,
//     int num_towers)
// {
//     int in_control_area1 = 0;
//     int in_control_area2 = 0;

//     if ((aircraft1->speed == 0) || (aircraft2->speed == 0))
//         return;
//     for (int i = 0; i < num_towers; i++) {
//         if (is_in_control_area(aircraft1, &towers[i]))
//             in_control_area1 = 1;
//         if (is_in_control_area(aircraft2, &towers[i]))
//             in_control_area2 = 1;
//     }
//     if ((in_control_area1) && (in_control_area2))
//         return;
//     if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
//         aircraft1->speed = 0;
//         aircraft2->speed = 0;
//         handle_aircraft_visibility(aircraft1, sfRed);
//         handle_aircraft_visibility(aircraft2, sfRed);
//     }
// }

int is_intersecting_aircrafts(aircraft_t *a1, aircraft_t *a2)
{
    sfVector2f pos1 = sfRectangleShape_getPosition(a1->shape);
    sfVector2f pos2 = sfRectangleShape_getPosition(a2->shape);
    float distX = pos1.x - pos2.x;
    float distY = pos1.y - pos2.y;
    float distance = sqrt(distX * distX + distY * distY);

    return (distance <= 20 + COLLISION_TOLERANCE);
}

void check_and_handle_collision(aircraft_t *aircraft1, aircraft_t *aircraft2,
    control_tower_t *towers, int num_towers)
{
    int in_control_area1 = 0;
    int in_control_area2 = 0;

    if ((aircraft1->speed == 0) || (aircraft2->speed == 0))
        return;
    for (int i = 0; i < num_towers; i++) {
        if (is_in_control_area(aircraft1, &towers[i]))
            in_control_area1 = 1;
        if (is_in_control_area(aircraft2, &towers[i]))
            in_control_area2 = 1;
    }
    if ((in_control_area1) && (in_control_area2))
        return;
    if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
        aircraft1->speed = 0;
        aircraft2->speed = 0;
        handle_aircraft_visibility(aircraft1, sfRed);
        handle_aircraft_visibility(aircraft2, sfRed);
    }
}

int is_in_control_area(aircraft_t *aircraft, control_tower_t *tower)
{
    sfVector2f pos = sfRectangleShape_getPosition(aircraft->shape);
    float dx = pos.x - tower->position.x;
    float dy = pos.y - tower->position.y;
    float distance = sqrt(dx * dx + dy * dy);

    return (distance <= tower->radius);
}

void handle_aircraft_visibility(aircraft_t *aircraft, sfColor color)
{
    sfRectangleShape_setOutlineColor(aircraft->shape, color);
    sfSprite_setColor(aircraft->sprite, sfTransparent);
    sfRectangleShape_setFillColor(aircraft->shape, sfTransparent);
}

// void check_and_handle_collision(aircraft_t *aircraft1,
//         aircraft_t *aircraft2)
// {
//     if ((aircraft1->speed == 0) || (aircraft2->speed == 0))
//         return;
//     if (is_intersecting_aircrafts(aircraft1, aircraft2)) {
//         aircraft1->speed = 0;
//         aircraft2->speed = 0;
//     }
// }

// void handle_aircraft_collisions(section_t **sections, int row, int col)
// {
//     aircraft_node_t *node1;
//     aircraft_node_t *node2;

//     node1 = sections[row][col].aircrafts;
//     while (node1 != NULL) {
//         node2 = node1->next;
//         while (node2 != NULL) {
//             if (is_intersecting_aircrafts(node1->aircraft,
//                      node2->aircraft)) {
//                 sfRectangleShape_setFillColor
//                      (node1->aircraft->shape, sfWhite);
//                 sfRectangleShape_setFillColor
//                      (node2->aircraft->shape, sfWhite);
//                 node1->aircraft->speed = 0;
//                 node2->aircraft->speed = 0;
//             }
//             node2 = node2->next;
//         }
//         node1 = node1->next;
//     }
// }
