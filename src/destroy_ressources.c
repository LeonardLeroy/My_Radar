/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** destroy_ressources.c
*/

#include "my_radar.h"

void destroy_resources(sfRenderWindow *window, entities_params_t *params,
    texture_manager_t *manager)
{
    if (window != NULL)
        destroy_resources_window(window);
    if (params != NULL)
        destroy_resources_params(params);
    if (manager != NULL)
        destroy_texture_manager(manager);
}

void destroy_resources_window(sfRenderWindow *window)
{
    if (window != NULL)
        sfRenderWindow_destroy(window);
    window = NULL;
}

void destroy_resources_params_aircrafts(entities_params_t *params)
{
    for (int i = 0; i < params->num_aircrafts; i++) {
        if ((params->aircrafts)[i].shape) {
            sfRectangleShape_destroy((params->aircrafts)[i].shape);
            (params->aircrafts)[i].shape = NULL;
        }
        if ((params->aircrafts)[i].sprite) {
            sfSprite_destroy((params->aircrafts)[i].sprite);
            (params->aircrafts)[i].sprite = NULL;
        }
    }
    if (params->aircrafts) {
        free(params->aircrafts);
        params->aircrafts = NULL;
    }
}

void destroy_resources_params_towers(entities_params_t *params)
{
    for (int i = 0; i < params->num_towers; i++) {
        if ((params->towers)[i].area) {
            sfCircleShape_destroy((params->towers)[i].area);
            (params->towers)[i].area = NULL;
        }
        if ((params->towers)[i].sprite) {
            sfSprite_destroy((params->towers)[i].sprite);
            (params->towers)[i].sprite = NULL;
        }
    }
    if (params->towers) {
        free(params->towers);
        params->towers = NULL;
    }
}

void destroy_resources_params(entities_params_t *params)
{
    if (params != NULL) {
        destroy_resources_params_aircrafts(params);
        destroy_resources_params_towers(params);
    }
}
