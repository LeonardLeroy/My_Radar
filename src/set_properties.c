/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** set_properties.c
*/

#include "my_radar.h"

void set_aircraft_properties(aircraft_t *aircraft, sfVector2f departure)
{
    sfVector2f sprite_size = {20, 20};

    sfRectangleShape_setSize(aircraft->shape, sprite_size);
    sfSprite_setScale(aircraft->sprite, (sfVector2f){0.1, 0.1});
    sfRectangleShape_setPosition(aircraft->shape, departure);
    sfRectangleShape_setFillColor(aircraft->shape, sfTransparent);
    sfRectangleShape_setOutlineColor(aircraft->shape, sfWhite);
    sfRectangleShape_setOutlineThickness(aircraft->shape, 1);
    if (!aircraft->texture)
        my_putstr("Erreur: Texture de l'avion non chargée\n");
}

void set_tower_properties(control_tower_t *tower, sfVector2f position,
    float radius)
{
    sfFloatRect sprite_bounds;
    sfVector2f origin;
    sfVector2f sprite_scale = {0.1, 0.1};
    sfVector2f sprite_position;

    sfCircleShape_setRadius(tower->area, radius);
    origin = (sfVector2f){radius, radius};
    sfCircleShape_setOrigin(tower->area, origin);
    sfCircleShape_setPosition(tower->area, position);
    sfCircleShape_setFillColor(tower->area, sfTransparent);
    sfCircleShape_setOutlineColor(tower->area, sfWhite);
    sfCircleShape_setOutlineThickness(tower->area, 1);
    sfSprite_setScale(tower->sprite, sprite_scale);
    sprite_bounds = sfSprite_getGlobalBounds(tower->sprite);
    sprite_position = (sfVector2f){position.x - (sprite_bounds.width / 2),
        position.y - (sprite_bounds.height / 2)};
    sfSprite_setPosition(tower->sprite, sprite_position);
}
