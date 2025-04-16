/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** window.c
*/

#include "my_radar.h"

sfRenderWindow *create_window(unsigned int width, unsigned int height,
    const char *title)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, title, sfClose, NULL);

    if (window)
        sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

sfSprite *create_background_sprite(const char *file_path)
{
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);
    sfSprite *background_sprite;

    if (!texture) {
        my_putstr("Erreur: Impossible de charger l'image de fond\n");
        return (NULL);
    }
    background_sprite = sfSprite_create();
    sfSprite_setTexture(background_sprite, texture, sfTrue);
    return (background_sprite);
}
