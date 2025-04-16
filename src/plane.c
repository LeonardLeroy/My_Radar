/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** aircraft.c
*/

#include "my_radar.h"

// sfVector2f calc_vector(sfVector2f departure, sfVector2f arrival)
// {
//     sfVector2f vector;
//     vector.x = arrival.x - departure.x;
//     vector.y = arrival.y - departure.y;
//     return (vector);
// }

// void angle(aircraft_t *aircraft)
// {
//     float angle =
//         atanf(aircraft->vector.x / aircraft->vector.y) * 180.0 / M_PI;
//     float end = aircraft->departure.y + aircraft->vector.y;

//     if (aircraft->departure.y <= end)
//         angle = 180.0 - angle;
//     else
//         angle *= -1.0;
//     sfRectangleShape_setRotation(aircraft->shape, -45);
//     sfSprite_setRotation(aircraft->sprite, -45);
//     sfRectangleShape_rotate(aircraft->shape, angle);
//     sfSprite_rotate(aircraft->sprite, angle);
//     aircraft->angle = angle;
// }

// aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
//     float speed, float delay)
// {
//     aircraft_t *aircraft = malloc(sizeof(aircraft_t));

//     if (!aircraft) {
//         my_putstr("Erreur : Allocation mémoire pour l'avion\n");
//         return (NULL);
//     }
//     aircraft->departure = departure;
//     aircraft->arrival = arrival;
//     aircraft->speed = speed;
//     aircraft->delay = delay;
//     aircraft->vector = calc_vector(departure, arrival);
//     aircraft->clock = sfClock_create();
//     if (!aircraft->clock) {
//         my_putstr("Erreur : Échec de l'initialisation de l'horloge\n");
//         free(aircraft);
//         return (NULL);
//     }
//     if (!init_aircraft_shape(aircraft) ||
//            !load_aircraft_texture(aircraft)) {
//         sfRectangleShape_destroy(aircraft->shape);
//         free(aircraft);
//         my_putstr("Erreur : Échec de l'initialisation de la forme ou de la "
//             "texture de l'avion\n");
//         return (NULL);
//     }
//     set_aircraft_properties(aircraft, departure);
//     angle(aircraft);
//     return (aircraft);
// }

aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
    float speeddelay[2], texture_manager_t *texture_manager)
{
    aircraft_t *aircraft = init_aircraft(departure, arrival, speeddelay[0],
        speeddelay[1]);

    if (!aircraft) {
        my_putstr("Erreur : Échec de l'initialisation de l'avion\n");
        return (NULL);
    }
    if (!init_aircraft_shape(aircraft)
        || !set_aircraft_texture(aircraft, texture_manager->textures[0])) {
        if (aircraft->shape)
            sfRectangleShape_destroy(aircraft->shape);
        free(aircraft);
        my_putstr("Erreur : Échec de l'initialisation de la forme ou de la "
            "texture de l'avion\n");
        return (NULL);
    }
    set_aircraft_properties(aircraft, departure);
    return (aircraft);
}

int set_aircraft_texture(aircraft_t *aircraft, sfTexture *texture)
{
    if (!texture) {
        my_putstr("Erreur : Texture de l'avion non chargée\n");
        return (0);
    }
    aircraft->texture = texture;
    aircraft->sprite = sfSprite_create();
    sfSprite_setTexture(aircraft->sprite, aircraft->texture, sfTrue);
    return (1);
}

aircraft_t *init_aircraft(sfVector2f departure, sfVector2f arrival,
    float speed, float delay)
{
    aircraft_t *aircraft = malloc(sizeof(aircraft_t));

    if (!aircraft)
        return NULL;
    aircraft->departure = departure;
    aircraft->arrival = arrival;
    aircraft->speed = speed;
    aircraft->delay = delay;
    aircraft->vector = (sfVector2f){0, 0};
    aircraft->clock = sfClock_create();
    aircraft->start_time = sfClock_getElapsedTime(aircraft->clock);
    aircraft->angle = 0.0f;
    return (aircraft);
}

int init_aircraft_shape(aircraft_t *aircraft)
{
    aircraft->shape = sfRectangleShape_create();
    if (!aircraft->shape) {
        my_putstr("Erreur : Échec de la création de la forme de l'avion\n");
        return (0);
    }
    return (1);
}

int load_aircraft_texture(aircraft_t *aircraft)
{
    aircraft->texture = sfTexture_createFromFile("assets/aircraft.png", NULL);
    if (!aircraft->texture) {
        my_putstr("Erreur : Échec du chargement de la texture de l'avion\n");
        return (0);
    }
    aircraft->sprite = sfSprite_create();
    sfSprite_setTexture(aircraft->sprite, aircraft->texture, sfTrue);
    return (1);
}

// void set_aircraft_properties(aircraft_t *aircraft, sfVector2f departure)
// {
//     sfVector2f sprite_size = {10, 10};

//     sfRectangleShape_setSize(aircraft->shape, sprite_size);
//     sfSprite_setScale(aircraft->sprite, (sfVector2f){0.1, 0.1});
//     sfRectangleShape_setPosition(aircraft->shape, departure);
//     sfRectangleShape_setFillColor(aircraft->shape, sfTransparent);
//     sfRectangleShape_setOutlineColor(aircraft->shape, sfWhite);
//     sfRectangleShape_setOutlineThickness(aircraft->shape, 1);
//     if (!aircraft->texture)
//         my_putstr("Erreur: Texture de l'avion non chargée\n");
// }

// aircraft_t *init_aircraft(sfVector2f departure, sfVector2f arrival,
//     float speed, float delay)
// {
//     aircraft_t *aircraft = malloc(sizeof(aircraft_t));

//     if (!aircraft) {
//         my_putstr("Erreur : Allocation mémoire pour l'avion\n");
//         return (NULL);
//     }
//     aircraft->departure = departure;
//     aircraft->arrival = arrival;
//     aircraft->speed = speed;
//     aircraft->delay = delay;
//     return (aircraft);
// }

// int init_aircraft_shape(aircraft_t *aircraft)
// {
//     if (!aircraft->shape)
//         return (0);
//     sfRectangleShape_setSize(aircraft->shape, (sfVector2f){20, 20});
//     sfRectangleShape_setFillColor(aircraft->shape, sfGreen);
//     sfRectangleShape_setOrigin(aircraft->shape, (sfVector2f){10, 10});
//     sfRectangleShape_setPosition(aircraft->shape, aircraft->departure);
//     return (1);
// }
