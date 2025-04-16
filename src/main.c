/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** main.c
*/

#include "my_radar.h"

int main(int argc, char **argv)
{
    int iError = NO_ERROR;
    sfRenderWindow *window = NULL;
    sfSprite *background_sprite = NULL;
    texture_manager_t *texture_manager = NULL;
    entities_params_t params = {NULL, 0, NULL, 0};

    iError = handle_arguments(argc, argv);
    if (iError == NO_ERROR)
        iError = main_init_texture(texture_manager, &params, argv[1]);
    if (iError == NO_ERROR) {
        background_sprite = create_background_sprite("assets/worldmap.png");
        window = create_window(WIDTH, HEIGHT, "My Airline Trafic Simulator");
    }
    if ((iError == NO_ERROR)
        && ((background_sprite == NULL) || (window == NULL)))
        iError = (background_sprite == NULL) ? ERROR_BACKGROUND : ERROR_WINDOW;
    if (iError == NO_ERROR)
        iError = game_loop(window, &params, background_sprite);
    destroy_resources(window, &params, texture_manager);
    return (write_error(iError));
}

int main_init_texture(texture_manager_t *texture_manager,
    entities_params_t *params, char *sfile)
{
    int iError = NO_ERROR;
    const char *texture_files[] = {"assets/aircraft.png", "assets/tower.png"};
    int num_textures = sizeof(texture_files) / sizeof(texture_files[0]);

    texture_manager = init_texture_manager(num_textures);
    if (texture_manager == NULL)
        iError = ERROR_TEXTURE;
    if (iError == NO_ERROR)
        iError = load_all_textures(texture_manager, texture_files);
    if (iError == NO_ERROR)
        iError = load_entities_from_script(sfile, params, texture_manager);
    return (iError);
}

// void end_of_main(sfRenderWindow *window, sfSprite *background_sprite,
//     entities_params_t params, texture_manager_t *texture_manager)
// {
//     game_loop(window, &params, background_sprite);
//     destroy_resources(window, &params);
//     destroy_texture_manager(texture_manager);
// }

// int main(int argc, char **argv)
// {
//     sfRenderWindow *window;
//     sfSprite *background_sprite;
//     entities_params_t params;
//     aircraft_t *aircrafts = NULL;
//     control_tower_t *towers = NULL;
//     int num_aircrafts = 0;
//     int num_towers = 0;
//     int arg_status;

//     arg_status = handle_arguments(argc, argv);
//     if (arg_status != 0)
//         return (arg_status == 84 ? 84 : 0);
//     background_sprite = create_background_sprite("assets/worldmap.png");
//     window = create_window(1920, 1080, "My Radar");
//     initialize_params(&params, &(params_wrapper_t)
//          {&aircrafts, &num_aircrafts,
//         &towers, &num_towers});
//     load_entities_from_script(argv[1], &params);
//     if ((!window) || (!params.aircrafts) || (!params.towers))
//         return (84);
//     game_loop(window, &params, background_sprite);
//     destroy_resources(window, &params);
//     return (0);
// }

// int main(int argc, char **argv)
// {
//     sfRenderWindow *window;
//     entities_params_t params;
//     params_wrapper_t wrapper;
//     aircraft_t *aircrafts = NULL;
//     control_tower_t *towers = NULL;
//     int num_aircrafts = 0;
//     int num_towers = 0;
//     int arg_status = handle_arguments(argc, argv);

//     if (arg_status == 84)
//         return (84);
//     if (arg_status == 1)
//         return (0);
//     window = create_window(1920, 1080, "My Radar");
//     wrapper = (params_wrapper_t){&aircrafts, &num_aircrafts, &towers,
//         &num_towers};
//     initialize_params(&params, &wrapper);
//     load_entities_from_script(argv[1], &params);
//     if (!window || !params.aircrafts || !params.towers)
//         return (84);
//     game_loop(window, &params);
//     destroy_resources(window, &params);
//     return (0);
// }
