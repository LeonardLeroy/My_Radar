/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** update_aicraft_positions.c
*/

#include "my_radar.h"

// void check_and_add_aircraft(section_t **sections, aircraft_params_t *params)
// {

//     if ((params->row >= 0) && (params->row < GRID_ROWS) &&
//      (params->col >= 0)
//         && (params->col < GRID_COLS))
//         add_aircraft_to_section(sections, params->row, params->col,
//             params->aircraft);
// }

int check_and_add_aircraft(section_t **sections, aircraft_params_t *params)
{
    int iError = NO_ERROR;
    aircraft_node_t *new_node = NULL;
    int col = params->pos.x / SECTION_SIZE;
    int row = params->pos.y / SECTION_SIZE;

    if ((row >= 0) && (row < GRID_ROWS) && (col >= 0) && (col < GRID_COLS)) {
        new_node = malloc(sizeof(aircraft_node_t));
        if (!new_node)
            iError = 84;
        else {
            new_node->aircraft = params->aircraft;
            new_node->next = sections[row][col].aircrafts;
            sections[row][col].aircrafts = new_node;
            sections[row][col].num_aircrafts++;
        }
    }
    return (iError);
}

void handle_collisions_and_cleanup(section_t **sections,
    control_tower_t *towers, int num_towers)
{
    process_collisions(sections, towers, num_towers);
    free_sections(sections);
}

int update_aircraft_positions(entities_params_t *params)
{
    int iError = NO_ERROR;
    aircraft_t *aircrafts = params->aircrafts;
    section_t **sections = initialize_sections(GRID_ROWS, GRID_COLS);
    sfVector2f pos;
    aircraft_params_t aircraft_params;

    if ((!sections))
        iError = ERROR_SECTION;
    else {
        for (int i = 0; (i < params->num_aircrafts) && (iError == NO_ERROR);
            i++) {
            update_aircraft_position(&aircrafts[i]);
            pos = sfRectangleShape_getPosition(aircrafts[i].shape);
            aircraft_params = (aircraft_params_t){pos, &aircrafts[i]};
            iError = check_and_add_aircraft(sections, &aircraft_params);
        }
        handle_collisions_and_cleanup(sections, params->towers,
            params->num_towers);
    }
    return (iError);
}

// void add_aircraft_to_section(section_t **sections, int row, int col,
//     aircraft_t *aircraft)
// {
//     aircraft_node_t *new_node = malloc(sizeof(aircraft_node_t));

//     if (!new_node) {
//         my_putstr("Memory allocation failed for new aircraft node.\n");
//         return;
//     }
//     new_node->aircraft = aircraft;
//     new_node->next = sections[row][col].aircrafts;
//     sections[row][col].aircrafts = new_node;
//     sections[row][col].num_aircrafts++;
// }

// void check_and_add_aircraft(section_t **sections, aircraft_params_t *params)
// {
//     if ((params->row >= 0) && (params->row < GRID_ROWS)
//         && (params->col >= 0)
//         && (params->col < GRID_COLS))
//         add_aircraft_to_section(sections, params->row, params->col,
//             params->aircraft);
// }

// void handle_collisions_and_cleanup(section_t **sections,
//     control_tower_t *towers, int num_towers, control_tower_t *tower)
// {
//     process_collisions(sections, towers, num_towers, tower);
//     free_sections(sections);
// }

// void update_aircraft_positions(entities_params_t *params)
// {
//     int i;
//     int row;
//     int col;
//     aircraft_t *aircrafts = *(params->aircrafts);
//     int num_aircrafts = *(params->num_aircrafts);
//     control_tower_t *towers = *(params->towers);
//     int num_towers = *(params->num_towers);
//     section_t **sections = initialize_sections(GRID_ROWS, GRID_COLS);
//     sfVector2f pos;
//     aircraft_params_t aircraft_params;

//     for (i = 0; i < num_aircrafts; i++) {
//         update_aircraft_position(&aircrafts[i]);
//         pos = sfRectangleShape_getPosition(aircrafts[i].shape);
//         col = pos.x / SECTION_SIZE;
//         row = pos.y / SECTION_SIZE;
//         aircraft_params = (aircraft_params_t){row, col, pos, &aircrafts[i]};
//         check_and_add_aircraft(sections, &aircraft_params);
//     }
//     handle_collisions_and_cleanup(sections, towers, num_towers, NULL);
// }

// void add_aircraft_to_section(section_t **sections, int row, int col,
//     aircraft_t *aircraft)
// {
//     aircraft_node_t *new_node = malloc(sizeof(aircraft_node_t));

//     if (!new_node) {
//         my_putstr("Memory allocation failed for new aircraft node.\n");
//         return;
//     }
//     new_node->aircraft = aircraft;
//     new_node->next = sections[row][col].aircrafts;
//     sections[row][col].aircrafts = new_node;
//     sections[row][col].num_aircrafts++;
// }
