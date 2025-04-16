/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** handle_event.c
*/

#include "my_radar.h"

void handle_window_close(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void handle_events(sfRenderWindow *window, display_params_t *display)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        handle_window_close(window, event);
        handle_key_press(event, display);
    }
}

void handle_key_press(sfEvent event, display_params_t *display)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeyG:
                display->show_grid = !(display->show_grid);
                break;
            case sfKeyL:
                display->show_hitboxes = !(display->show_hitboxes);
                break;
            case sfKeyS:
                display->show_sprites = !(display->show_sprites);
                break;
            case sfKeyC:
                display->show_chronometer = !(display->show_chronometer);
                break;
            default:
                break;
        }
    }
}

// void handle_key_press(sfEvent event, int *show_grid, int *show_hitboxes,
//     int *show_sprites)
// {
//     if (event.type == sfEvtKeyPressed) {
//         switch (event.key.code) {
//             case sfKeyG:
//                 *show_grid = !(*show_grid);
//                 break;
//             case sfKeyL:
//                 *show_hitboxes = !(*show_hitboxes);
//                 break;
//             case sfKeyS:
//                 *show_sprites = !(*show_sprites);
//                 break;
//             default:
//                 break;
//         }
//     }
// }

// void handle_events(sfRenderWindow *window, int *show_grid,
//        int *show_hitboxes,
//     int *show_sprites)
// {
//     sfEvent event;

//     while (sfRenderWindow_pollEvent(window, &event)) {
//         handle_window_close(window, event);
//         handle_key_press(event, show_grid, show_hitboxes, show_sprites);
//     }
// }
