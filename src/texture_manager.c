/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** texture_manager.c
*/

#include "my_radar.h"

texture_manager_t *init_texture_manager(int num_textures)
{
    texture_manager_t *manager = malloc(sizeof(texture_manager_t));

    if (!manager) {
        my_putstr("Failed to allocate memory for texture manager.\n");
        return (NULL);
    }
    manager->textures = malloc(num_textures * sizeof(sfTexture *));
    if (!manager->textures) {
        my_putstr("Failed to allocate memory for textures.\n");
        free(manager);
        return (NULL);
    }
    manager->num_textures = num_textures;
    for (int i = 0; i < num_textures; i++) {
        manager->textures[i] = NULL;
    }
    return (manager);
}

int load_all_textures(texture_manager_t *manager, const char **file_paths)
{
    int iError = NO_ERROR;

    for (int i = 0; i < manager->num_textures; i++) {
        manager->textures[i] = load_texture(file_paths[i]);
        if (!manager->textures[i]) {
            my_putstr("Failed to load texture\n");
            free_texture_manager(manager);
            iError = ERROR_TEXTURE;
            break;
        }
    }
    return (iError);
}

void destroy_texture_manager(texture_manager_t *manager)
{
    if (!manager) {
        return;
    }
    for (int i = 0; i < manager->num_textures; i++) {
        if (manager->textures[i]) {
            sfTexture_destroy(manager->textures[i]);
            manager->textures[i] = NULL;
        }
    }
    free(manager->textures);
    free(manager);
}

sfTexture *load_texture(const char *file_path)
{
    sfTexture *texture = sfTexture_createFromFile(file_path, NULL);

    if (!texture) {
        my_putstr("Erreur: Impossible de charger la texture\n");
    }
    return (texture);
}

void free_texture_manager(texture_manager_t *manager)
{
    if (!manager) {
        my_putstr("Texture manager is already NULL.\n");
        return;
    }
    for (int i = 0; i < manager->num_textures; i++) {
        if (manager->textures[i]) {
            sfTexture_destroy(manager->textures[i]);
        }
    }
    free(manager->textures);
    free(manager);
}
