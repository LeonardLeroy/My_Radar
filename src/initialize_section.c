/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** initialize_section.c
*/

#include "my_radar.h"

// section_t **initialize_sections(int rows, int cols)
// {
//     section_t **sections = malloc(rows * sizeof(section_t *));

//     for (int i = 0; i < rows; i++) {
//         sections[i] = malloc(cols * sizeof(section_t));
//         for (int j = 0; j < cols; j++) {
//             sections[i][j].bounds =
//                 (sfIntRect){j * SECTION_SIZE, i *
//                     SECTION_SIZE, SECTION_SIZE,
//                     SECTION_SIZE};
//             sections[i][j].aircrafts = NULL;
//             sections[i][j].num_aircrafts = 0;
//         }
//     }
//     return (sections);
// }

// section_t **initialize_sections(int rows, int cols)
// {
//     section_t **sections = malloc(rows * sizeof(section_t *));

//     if (!sections) {
//         my_putstr("Memory allocation failed for sections.\n");
//         exit(84);
//     }
//     for (int i = 0; i < rows; i++) {
//         sections[i] = malloc(cols * sizeof(section_t));
//         if (!sections[i]) {
//             my_putstr("Memory allocation failed for sections.\n");
//             exit(84);
//         }
//         for (int j = 0; j < cols; j++) {
//             sections[i][j].bounds =
//                 (sfIntRect){j * SECTION_SIZE, i * SECTION_SIZE,
//                     SECTION_SIZE, SECTION_SIZE};
//             sections[i][j].aircrafts = NULL;
//             sections[i][j].num_aircrafts = 0;
//         }
//     }
//     return (sections);
// }

// section_t **initialize_sections(int rows, int cols)
// {
//     section_t **sections = malloc(rows * sizeof(section_t *));

//     if (!sections) {
//         my_putstr("Memory allocation failed for sections.\n");
//         exit(84);
//     }
//     for (int i = 0; i < rows; i++) {
//         sections[i] = malloc(cols * sizeof(section_t));
//         if (!sections[i]) {
//             my_putstr("Memory allocation failed for sections.\n");
//             exit(84);
//         }
//         for (int j = 0; j < cols; j++) {
//             sections[i][j].bounds =
//                 (sfIntRect){j * SECTION_SIZE, i
//                      * SECTION_SIZE, SECTION_SIZE,
//                     SECTION_SIZE};
//             sections[i][j].aircrafts = NULL;
//             sections[i][j].num_aircrafts = 0;
//         }
//     }
//     return (sections);
// }

void init_section(section_t *section, int j, int i)
{
    section->bounds = (sfIntRect){j * SECTION_SIZE, i * SECTION_SIZE,
        SECTION_SIZE, SECTION_SIZE};
    section->aircrafts = NULL;
    section->num_aircrafts = 0;
}

section_t **initialize_sections(int rows, int cols)
{
    section_t **sections = malloc(rows * sizeof(section_t *));

    if (!sections)
        return (NULL);
    for (int i = 0; i < rows; i++) {
        sections[i] = malloc(cols * sizeof(section_t));
        if (!sections[i]) {
            free_sections(sections);
            break;
        }
        for (int j = 0; j < cols; j++) {
            init_section(&sections[i][j], j, i);
        }
    }
    return (sections);
}

void free_aircrafts_in_section(aircraft_node_t *aircrafts)
{
    aircraft_node_t *current = aircrafts;
    aircraft_node_t *temp;

    while (current) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

void free_sections(section_t **sections)
{
    int row;
    int col;

    for (row = 0; row < GRID_ROWS; row++) {
        if (!sections[row])
            break;
        for (col = 0; col < GRID_COLS; col++) {
            free_aircrafts_in_section(sections[row][col].aircrafts);
        }
        free(sections[row]);
    }
    free(sections);
}
