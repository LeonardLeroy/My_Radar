/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** game_loop_destroy_ressources.c
*/

#include "my_radar.h"

// void game_loop(sfRenderWindow *window, entities_params_t *params)
// {
//     display_params_t display = {0, 0, 1};

//     while (sfRenderWindow_isOpen(window)) {
//         handle_events_wrapper(window, &display);
//         sfRenderWindow_clear(window, sfBlack);
//         update_positions_wrapper(params);
//         if (are_aircrafts_in_motion(params) == 0) {
//             sfRenderWindow_close(window);
//             break;
//         }
//         draw_elements(window, params, &display);
//         sfRenderWindow_display(window);
//     }
// }

/////////////////////////////////////////////////////////

// void game_loop(sfRenderWindow *window, entities_params_t *params,
//                sfSprite *background_sprite)
// {
//     display_params_t display = {0, 0, 1};

//     while (sfRenderWindow_isOpen(window)) {
//         handle_events_wrapper(window, &display);
//         sfRenderWindow_clear(window, sfBlack);
//         if (background_sprite)
//             sfRenderWindow_drawSprite(window, background_sprite, NULL);
//         update_positions_wrapper(params);
//         if (are_aircrafts_in_motion(params) == MYFALSE) {
//             sfRenderWindow_close(window);
//             break;
//         }
//         draw_elements(window, params, &display);
//         sfRenderWindow_display(window);
//     }
// }

// void handle_events_wrapper(sfRenderWindow *window,
//       display_params_t *display)
// {
//     handle_events(window, &display->show_grid, &display->show_hitboxes,
//                   &display->show_sprites);
// }


// void draw_elements(sfRenderWindow *window, entities_params_t *params,
//                    display_params_t *display)
// {
//     if (display->show_grid)
//         draw_grid(window);
//     for (int i = 0; i < params->num_aircrafts; i++)
//         draw_aircraft(window, &(params->aircrafts)[i],
//            display->show_hitboxes,
//                       display->show_sprites);
//     for (int i = 0; i < params->num_towers; i++)
//         draw_control_tower(window, &(params->towers)[i],
//                            display->show_hitboxes, display->show_sprites);
// }

int game_loop(sfRenderWindow *window, entities_params_t *params,
    sfSprite *background_sprite)
{
    int iError = NO_ERROR;
    display_params_t display = {0, 0, 1, 0};
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        handle_events_wrapper(window, &display);
        sfRenderWindow_clear(window, sfBlack);
        if (background_sprite)
            sfRenderWindow_drawSprite(window, background_sprite, NULL);
        iError = update_positions_wrapper(params);
        if (are_aircrafts_in_motion(params) == MYFALSE)
            break;
        draw_elements(window, params, &display);
        draw_chronometer(window, clock, &display);
        sfRenderWindow_display(window);
    }
    sfClock_destroy(clock);
    display_simulation_results(params);
    return (iError);
}

void handle_events_wrapper(sfRenderWindow *window, display_params_t *display)
{
    handle_events(window, display);
}

int update_positions_wrapper(entities_params_t *params)
{
    int iError = NO_ERROR;

    iError = update_aircraft_positions(params);
    return (iError);
}

int are_aircrafts_in_motion(entities_params_t *params)
{
    float speed;

    for (int i = 0; i < params->num_aircrafts; i++) {
        speed = (params->aircrafts)[i].speed;
        if (speed > SPEED_TOLERANCE)
            return (MYTRUE);
    }
    return (MYFALSE);
}

void draw_elements(sfRenderWindow *window, entities_params_t *params,
    display_params_t *display)
{
    if (display->show_grid)
        draw_grid(window);
    for (int i = 0; i < params->num_aircrafts; i++)
        draw_aircraft(window, &(params->aircrafts)[i], display->show_hitboxes,
            display->show_sprites);
    for (int i = 0; i < params->num_towers; i++)
        draw_control_tower(window, &(params->towers)[i],
            display->show_hitboxes, display->show_sprites);
}

// int are_aircrafts_in_motion(entities_params_t *params)
// {
//     for (int i = 0; i < *(params->num_aircrafts); i++) {
//         if ((*(params->aircrafts))[i].speed != 0)
//             return (1);
//     }
//     return (0);
// }

// void game_loop(sfRenderWindow *window, entities_params_t *params)
// {
//     int show_grid = 0;
//     int show_hitboxes = 0;
//     int show_sprites = 1;
//     int aircrafts_in_motion;

//     while (sfRenderWindow_isOpen(window)) {
//         handle_events(window, &show_grid, &show_hitboxes, &show_sprites);
//         sfRenderWindow_clear(window, sfBlack);
//         update_aircraft_positions(params);
//         aircrafts_in_motion = 0;
//         for (int i = 0; i < *(params->num_aircrafts); i++) {
//             if ((*(params->aircrafts))[i].speed != 0)
//                 aircrafts_in_motion = 1;
//         }
//         if (aircrafts_in_motion == 0) {
//             sfRenderWindow_close(window);
//             break;
//         }
//         if (show_grid)
//             draw_grid(window);
//         for (int i = 0; i < *(params->num_aircrafts); i++)
//             draw_aircraft(window, &(*(params->aircrafts))[i], show_hitboxes,
//             show_sprites);
//         for (int i = 0; i < *(params->num_towers); i++)
//             draw_control_tower(window, &(*(params->towers))[i],
//                show_hitboxes,
//             show_sprites);
//         sfRenderWindow_display(window);
//     }
// }

// void game_loop(sfRenderWindow *window, entities_params_t *params)
// {
//     int i;

//     while (sfRenderWindow_isOpen(window)) {
//         handle_events(window);
//         sfRenderWindow_clear(window, sfBlack);
//         update_aircraft_positions(params);
//         for (i = 0; i < *(params->num_aircrafts); i++) {
//             draw_aircraft(window, &(*(params->aircrafts))[i]);
//         }
//         for (i = 0; i < *(params->num_towers); i++) {
//             draw_control_tower(window, &(*(params->towers))[i]);
//         }
//         sfRenderWindow_display(window);
//     }
// }
