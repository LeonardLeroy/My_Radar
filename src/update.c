/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** update.c
*/

#include "my_radar.h"

// void update_aircraft_positions(entities_params_t *params)
// {
//     int i;
//     int row;
//     int col;
//     aircraft_t *aircrafts = *(params->aircrafts);
//     int num_aircrafts = *(params->num_aircrafts);
//     section_t **sections = initialize_sections(GRID_ROWS, GRID_COLS);
//     sfVector2f pos;

//     for (i = 0; i < num_aircrafts; i++) {
//         update_aircraft_position(&aircrafts[i]);
//         pos = sfRectangleShape_getPosition(aircrafts[i].shape);
//         col = pos.x / SECTION_SIZE;
//         row = pos.y / SECTION_SIZE;
//         if ((row >= 0) && (row < GRID_ROWS) && (col >= 0)
//             && (col < GRID_COLS)) {
//             sections[row][col].aircrafts[sections[row][col].num_aircrafts] =
//                 &aircrafts[i];
//             sections[row][col].num_aircrafts++;
//         }
//     }
//     for (row = 0; row < GRID_ROWS; row++) {
//         for (col = 0; col < GRID_COLS; col++)
//             handle_aircraft_collisions(sections, row, col);
//     }
//     for (row = 0; row < GRID_ROWS; row++) {
//         for (col = 0; col < GRID_COLS; col++)
//             free(sections[row][col].aircrafts);
//         free(sections[row]);
//     }
//     free(sections);
// }

// void update_aircraft_positions(entities_params_t *params)
// {
//     int i;
//     int row;
//     int col;
//     aircraft_t *aircrafts = *(params->aircrafts);
//     int num_aircrafts = *(params->num_aircrafts);
//     section_t **sections = initialize_sections(GRID_ROWS, GRID_COLS);
//     sfVector2f pos;

//     for (i = 0; i < num_aircrafts; i++) {
//         update_aircraft_position(&aircrafts[i]);
//         pos = sfRectangleShape_getPosition(aircrafts[i].shape);
//         col = pos.x / SECTION_SIZE;
//         row = pos.y / SECTION_SIZE;
//         if ((row >= 0) && (row < GRID_ROWS) && (col >= 0) &&
//               (col < GRID_COLS))
//             add_aircraft_to_section(sections, row, col, &aircrafts[i]);
//     }
//     process_collisions(sections);
//     free_sections(sections);
// }

// void update_aircraft_position_else(sfVector2f *position,
//      sfVector2f direction, float speed, sfVector2f arrival)
// {
//     float length = sqrt(direction.x * direction.x +
//         direction.y * direction.y);
//     sfVector2f velocity = {0, 0};

//     if (length < 0.01) {
//         *position = arrival;
//         return;
//     }
//     direction.x /= length;
//     direction.y /= length;
//     velocity.x = direction.x * speed;
//     velocity.y = direction.y * speed;
//     position->x += velocity.x;
//     position->y += velocity.y;
//     if ((fabs(position->x - arrival.x) < 1) &&
//       (fabs(position->y - arrival.y) < 1)) {
//         *position = arrival;
//     }
// }

void update_aircraft_position_else(sfVector2f *position, sfVector2f direction,
    float speed, sfVector2f arrival)
{
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    sfVector2f velocity = {0, 0};

    direction.x /= length;
    direction.y /= length;
    velocity.x = direction.x * speed;
    velocity.y = direction.y * speed;
    position->x += velocity.x;
    position->y += velocity.y;
    if ((fabs(position->x - arrival.x) < 1)
        && (fabs(position->y - arrival.y) < 1))
        *position = arrival;
}

void update_sprite_position(aircraft_t *aircraft, sfVector2f position)
{
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(aircraft->sprite);
    sfFloatRect hitbox_bounds =
        sfRectangleShape_getGlobalBounds(aircraft->shape);
    sfVector2f sprite_position = {
        position.x - (sprite_bounds.width - hitbox_bounds.width) / 2,
        position.y - (sprite_bounds.height - hitbox_bounds.height) / 2};

    sfSprite_setPosition(aircraft->sprite, sprite_position);
}

void update_aircraft_position(aircraft_t *aircraft)
{
    sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
    sfVector2f direction = {aircraft->arrival.x - position.x,
        aircraft->arrival.y - position.y};
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);

    if ((aircraft->speed == 0)
        || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
            < aircraft->delay))
        return;
    if (length < POSITION_TOLERANCE) {
        position = aircraft->arrival;
        aircraft->speed = 0;
        handle_aircraft_visibility(aircraft, sfGreen);
    } else
        update_aircraft_position_else(&position, direction, aircraft->speed,
            aircraft->arrival);
    sfRectangleShape_setPosition(aircraft->shape, position);
    update_sprite_position(aircraft, position);
}

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x + direction.y
//      * direction.y);

//     if ((aircraft->speed == 0)
//         || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
//             < aircraft->delay))
//         return;
//     if (length < POSITION_TOLERANCE) {
//         position = aircraft->arrival;
//         aircraft->speed = 0;
//         handle_aircraft_visibility(aircraft, sfGreen);
//     } else
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(aircraft->sprite);
//     sfFloatRect hitbox_bounds =
//         sfRectangleShape_getGlobalBounds(aircraft->shape);
//     sfVector2f sprite_position = {
//         position.x - (sprite_bounds.width - hitbox_bounds.width) / 2,
//         position.y - (sprite_bounds.height - hitbox_bounds.height) / 2};
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, sprite_position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x + direction.y
//         * direction.y);

//     if ((aircraft->speed == 0)
//         || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
//             < aircraft->delay))
//         return;
//     if (length < POSITION_TOLERANCE) {
//         position = aircraft->arrival;
//         aircraft->speed = 0;
//         handle_aircraft_visibility(aircraft, sfGreen);
//     } else
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x +
//           direction.y * direction.y);
//     const float position_tolerance = 2.0f;

//     if ((aircraft->speed == 0)
//         || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
//             < aircraft->delay))
//         return;
//     if (length < position_tolerance) {
//         position = aircraft->arrival;
//         aircraft->speed = 0;
//         sfSprite_setColor(aircraft->sprite, sfTransparent);
//         sfRectangleShape_setOutlineColor(aircraft->shape, sfGreen);
//     } else
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x + direction.y
//         * direction.y);

//     if ((aircraft->speed == 0)
//         || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
//             < aircraft->delay))
//         return;
//     if (length < 1) {
//         position = aircraft->arrival;
//         aircraft->speed = 0;
//     } else {
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     }
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfTime current_time;
//     sfVector2f position;
//     sfVector2f direction;
//     float length;

//     if ((aircraft->speed == 0)
//         || (sfTime_asSeconds(sfClock_getElapsedTime(aircraft->clock))
//             < aircraft->delay))
//         return;
//     position = sfRectangleShape_getPosition(aircraft->shape);
//     direction = (sfVector2f){aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     length = sqrt(direction.x * direction.x + direction.y * direction.y);
//     if (length < 1) {
//         position = aircraft->arrival;
//         aircraft->speed = 0;
//     } else
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfTime current_time;
//     sfVector2f position;
//     sfVector2f direction;
//     float length;

//     if (aircraft->speed == 0)
//         return;
//     current_time = sfClock_getElapsedTime(aircraft->clock);
//     if (sfTime_asSeconds(current_time) < aircraft->delay)
//         return;
//     position = sfRectangleShape_getPosition(aircraft->shape);
//     direction = (sfVector2f){aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     length = sqrt(direction.x * direction.x + direction.y * direction.y);
//     if (length < 1) {
//         position = aircraft->arrival;
//     } else {
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     }
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x + direction.y
//          * direction.y);

//     if (length < 1) {
//         position = aircraft->arrival;
//     } else
//         update_aircraft_position_else(&position, direction, aircraft->speed,
//             aircraft->arrival);
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x + direction.y
//            * direction.y);
//     sfVector2f velocity = {0, 0};

//     if (length < 1) {
//         position = aircraft->arrival;
//     } else {
//         direction.x /= length;
//         direction.y /= length;
//         velocity.x = direction.x * aircraft->speed;
//         velocity.y = direction.y * aircraft->speed;
//         position.x += velocity.x;
//         position.y += velocity.y;
//         if ((fabs(position.x - aircraft->arrival.x) < 1)
//             && (fabs(position.y - aircraft->arrival.y) < 1))
//             position = aircraft->arrival;
//     }
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }

// void update_aircraft_positions(entities_params_t *params)
// {
//     int i, row, col;
//     aircraft_t *aircrafts = *(params->aircrafts);
//     int num_aircrafts = *(params->num_aircrafts);
//     section_t **sections = initialize_sections(GRID_ROWS, GRID_COLS);
//     sfVector2f pos;

//     for (i = 0; i < num_aircrafts; i++) {
//         update_aircraft_position(&aircrafts[i]);
//         pos = sfRectangleShape_getPosition(aircrafts[i].shape);
//         col = pos.x / SECTION_SIZE;
//         row = pos.y / SECTION_SIZE;
//         if ((row >= 0) && (row < GRID_ROWS) && (col >= 0) &&
//              (col < GRID_COLS))
//             add_aircraft_to_section(sections, row, col, &aircrafts[i]);
//     }
//     process_collisions(sections);
//     free_sections(sections);
// }

// void add_aircraft_to_section(section_t **sections, int row, int col,
//     aircraft_t *aircraft)
// {
//     sections[row][col].aircrafts[sections[row][col].num_aircrafts++] =
//         aircraft;
// }

// void process_collisions(section_t **sections)
// {
//     int row;
//     int col;

//     for (row = 0; row < GRID_ROWS; row++)
//         for (col = 0; col < GRID_COLS; col++)
//             handle_aircraft_collisions(sections, row, col);
// }

// void free_sections(section_t **sections)
// {
//     int row;
//     int col;

//     for (row = 0; row < GRID_ROWS; row++) {
//         for (col = 0; col < GRID_COLS; col++)
//             free(sections[row][col].aircrafts);
//         free(sections[row]);
//     }
//     free(sections);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f pos = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f dir = {aircraft->arrival.x - pos.x,
//         aircraft->arrival.y - pos.y};
//     float length = sqrt(dir.x * dir.x + dir.y * dir.y);
//     sfVector2f vel = {0, 0};

//     if (length < 1) {
//         pos = aircraft->arrival;
//     } else {
//         dir.x /= length;
//         dir.y /= length;
//         vel.x = dir.x * aircraft->speed;
//         vel.y = dir.y * aircraft->speed;
//         pos.x += vel.x;
//         pos.y += vel.y;
//         if ((fabs(pos.x - aircraft->arrival.x) < 1)
//             && (fabs(pos.y - aircraft->arrival.y) < 1))
//             pos = aircraft->arrival;
//     }
//     sfRectangleShape_setPosition(aircraft->shape, pos);
//     sfSprite_setPosition(aircraft->sprite, pos);
// }

// void update_aircraft_position(aircraft_t *aircraft)
// {
//     sfVector2f position = sfRectangleShape_getPosition(aircraft->shape);
//     sfVector2f direction = {aircraft->arrival.x - position.x,
//         aircraft->arrival.y - position.y};
//     float length = sqrt(direction.x * direction.x +
//            direction.y * direction.y);
//     sfVector2f velocity = {0, 0};

//     if (length < 1) {
//         position = aircraft->arrival;
//     } else {
//         direction.x /= length;
//         direction.y /= length;
//         velocity.x = direction.x * aircraft->speed;
//         velocity.y = direction.y * aircraft->speed;
//         position.x += velocity.x;
//         position.y += velocity.y;
//         if ((fabs(position.x - aircraft->arrival.x) < 1)
//             && (fabs(position.y - aircraft->arrival.y) < 1))
//             position = aircraft->arrival;
//     }
//     sfRectangleShape_setPosition(aircraft->shape, position);
//     sfSprite_setPosition(aircraft->sprite, position);
// }
