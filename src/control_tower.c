/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** control_tower.c
*/

#include "my_radar.h"

control_tower_t *create_control_tower(sfVector2f position, float radius,
    texture_manager_t *texture_manager)
{
    control_tower_t *tower = init_tower(position, radius);

    if (!tower)
        return (NULL);
    if (!init_tower_area(tower)
        || !set_tower_texture(tower, texture_manager->textures[1])) {
        if (tower->area)
            sfCircleShape_destroy(tower->area);
        free(tower);
        return (NULL);
    }
    set_tower_properties(tower, position, radius);
    return (tower);
}

int set_tower_texture(control_tower_t *tower, sfTexture *texture)
{
    if (!texture) {
        my_putstr("Erreur : Texture de la tour de contrôle non chargée\n");
        return (0);
    }
    tower->texture = texture;
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    return (1);
}

control_tower_t *init_tower(sfVector2f position, float radius)
{
    control_tower_t *tower = malloc(sizeof(control_tower_t));

    if (!tower)
        return (NULL);
    tower->position = position;
    tower->radius = radius;
    return (tower);
}

int init_tower_area(control_tower_t *tower)
{
    tower->area = sfCircleShape_create();
    return (tower->area != NULL);
}

int load_tower_texture(control_tower_t *tower)
{
    tower->texture = sfTexture_createFromFile("assets/tower.png", NULL);
    if (!tower->texture)
        return (0);
    tower->sprite = sfSprite_create();
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    return (1);
}

// void set_tower_properties(control_tower_t *tower, sfVector2f position,
//     float radius)
// {
//     sfFloatRect sprite_bounds;
//     sfVector2f origin;
//     sfVector2f sprite_scale = {0.1, 0.1};
//     sfVector2f sprite_position;

//     sfCircleShape_setRadius(tower->area, radius);
//     origin = (sfVector2f){radius, radius};
//     sfCircleShape_setOrigin(tower->area, origin);
//     sfCircleShape_setPosition(tower->area, position);
//     sfCircleShape_setFillColor(tower->area, sfTransparent);
//     sfCircleShape_setOutlineColor(tower->area, sfWhite);
//     sfCircleShape_setOutlineThickness(tower->area, 1);
//     sfSprite_setScale(tower->sprite, sprite_scale);
//     sprite_bounds = sfSprite_getGlobalBounds(tower->sprite);
//     sprite_position = (sfVector2f){position.x - (sprite_bounds.width / 2),
//         position.y - (sprite_bounds.height / 2)};
//     sfSprite_setPosition(tower->sprite, sprite_position);
// }

// void set_tower_properties(control_tower_t *tower, sfVector2f position,
//     float radius)
// {
//     sfCircleShape_setRadius(tower->area, radius / 2);
//     sfSprite_setScale(tower->sprite, (sfVector2f){0.1, 0.1});
//     sfCircleShape_setPosition(tower->area, position);
//     sfCircleShape_setFillColor(tower->area, sfTransparent);
//     sfCircleShape_setOutlineColor(tower->area, sfWhite);
//     sfCircleShape_setOutlineThickness(tower->area, 1);
// }
