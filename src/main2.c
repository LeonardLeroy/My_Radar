/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** main2.c
*/

#include "my_radar.h"

// int main(int argc, char **argv)
// {
//     sfRenderWindow *window;
//     sfSprite *background_sprite =
//         create_background_sprite("assets/worldmap.png");
//     aircraft_t *aircrafts = NULL;
//     control_tower_t *towers = NULL;
//     entities_params_t params;
//     int num_aircrafts = 0;
//     int num_towers = 0;
//     int arg_status;

//     arg_status = handle_arguments(argc, argv);
//     if (arg_status != 0)
//         return (arg_status == 84 ? 84 : 0);
//     window = create_window(1920, 1080, "My Radar");
//     initialize_params(&params, &(params_wrapper_t){&aircrafts,
//     &num_aircrafts,
//         &towers, &num_towers});
//     load_entities_from_script(argv[1], &params);
//     if ((!window) || (!params.aircrafts) || (!params.towers))
//         return (84);
//     end_of_main(window, background_sprite, params);
//     return (0);
// }

// texture_manager_t *initialize_and_load_textures(int num_textures,
//      const char **texture_files) {
//     texture_manager_t *texture_manager = init_texture_manager(num_textures);
//     if (!texture_manager)
//         return NULL;

//     if (!load_all_textures(texture_manager, texture_files)) {
//         destroy_texture_manager(texture_manager);
//         return NULL;
//     }

//     return texture_manager;
// }

// int initialize_window_and_sprite(sfRenderWindow **window,
//  sfSprite **background_sprite, texture_manager_t *texture_manager) {
//     *window = create_window(1920, 1080, "My Airline simulator");
//     if (!(*window)) {
//         destroy_texture_manager(texture_manager);
//         return 0;
//     }

//     *background_sprite = create_background_sprite("assets/worldmap.png");
//     if (!(*background_sprite)) {
//         sfRenderWindow_destroy(*window);
//         destroy_texture_manager(texture_manager);
//         return 0;
//     }

//     return 1;
// }

// int initialize_params_and_load_script(entities_params_t *params,
//    char *script_file, texture_manager_t *texture_manager) {
//     aircraft_t *aircrafts = NULL;
//     control_tower_t *towers = NULL;
//     int num_aircrafts = 0;
//     int num_towers = 0;

//     initialize_params(params, &(params_wrapper_t)
//        {&aircrafts, &num_aircrafts, &towers, &num_towers});
//     load_entities_from_script(script_file, params, texture_manager);

//     if (!(params->aircrafts) || !(params->towers)) {
//         destroy_texture_manager(texture_manager);
//         return 0;
//     }

//     return 1;
// }

// int main(int argc, char **argv) {
//     sfRenderWindow *window = NULL;
//     sfSprite *background_sprite = NULL;
//     entities_params_t params;
//     texture_manager_t *texture_manager;
//     const char *texture_files[] =
//       {"assets/aircraft.png", "assets/tower.png"};
//     int num_textures = sizeof(texture_files) / sizeof(texture_files[0]);
//     int arg_status;

//     arg_status = handle_arguments(argc, argv);
//     if (arg_status != 0) {
//         return (arg_status == 84 ? 84 : 0);
//     }
//     texture_manager = initialize_and_load_textures(num_textures,
//       texture_files);
//     if (!texture_manager)
//         return 84;
//     if (!initialize_window_and_sprite(&window,
//        &background_sprite, texture_manager))
//         return 84;
//     if (!initialize_params_and_load_script(&params, argv[1],
//        texture_manager))
//         return 84;
//     end_of_main(window, background_sprite, params, texture_manager);
//     return 0;
// }

void print_usage(void)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("USAGE\n\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script    The path to the script file.\n");
    my_putstr("OPTIONS\n\n");
    my_putstr("\t-h  print the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n\n");
    my_putstr("\t`L' key enable/disable hitboxes and areas.\n");
    my_putstr("\t`S' key enable/disable sprites.\n");
    my_putstr("\t`G' key enable/disable grid sections.\n");
    my_putstr("\t`C' key enable/disable chronometer.\n");
}

void bad_argument(char argc)
{
    my_putstr("./my_radar: bad arguments: ");
    my_put_nbr(argc - 1);
    my_putstr(" given but 84 is required\nretry with -h\n");
}

int handle_arguments(int argc, char **argv)
{
    int iError = NO_ERROR;

    if ((argc < 2) || (argc > 2)) {
        bad_argument(argc);
        iError = ERROR_BAD_ARGUMENT;
    } else if (my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        iError = 1;
    }
    return (iError);
}

void print_simulation_results(int total_aircrafts, int survived_aircrafts,
    int crashed_aircrafts)
{
    my_putstr("Simulation result:\n");
    my_putstr("Total aircraft: ");
    my_put_nbr(total_aircrafts);
    my_putstr("\nSurvived aircraft: ");
    my_put_nbr(survived_aircrafts);
    my_putstr("\nCrashed aircraft: ");
    my_put_nbr(crashed_aircrafts);
    my_putstr("\n");
}

void display_simulation_results(entities_params_t *params)
{
    int total_aircrafts = params->num_aircrafts;
    int survived_aircrafts = 0;
    int crashed_aircrafts = 0;
    sfColor outlineColor;

    for (int i = 0; i < total_aircrafts; i++) {
        outlineColor =
            sfRectangleShape_getOutlineColor(params->aircrafts[i].shape);
        if ((outlineColor.r == 255) && (outlineColor.g == 0)
            && (outlineColor.b == 0))
            crashed_aircrafts++;
        if ((outlineColor.r == 0) && (outlineColor.g == 255)
            && (outlineColor.b == 0))
            survived_aircrafts++;
    }
    print_simulation_results(total_aircrafts, survived_aircrafts,
        crashed_aircrafts);
}
