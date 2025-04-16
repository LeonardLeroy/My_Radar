/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** draw_functions.c
*/

#include "my_radar.h"

void draw_aircraft(sfRenderWindow *window, aircraft_t *aircraft,
    int show_hitboxes, int show_sprites)
{
    if ((show_sprites) && (aircraft->sprite))
        sfRenderWindow_drawSprite(window, aircraft->sprite, NULL);
    if ((show_hitboxes) && (aircraft->shape))
        sfRenderWindow_drawRectangleShape(window, aircraft->shape, NULL);
}

void draw_control_tower(sfRenderWindow *window, control_tower_t *tower,
    int show_hitboxes, int show_sprites)
{
    if ((show_sprites) && (tower->sprite))
        sfRenderWindow_drawSprite(window, tower->sprite, NULL);
    if ((show_hitboxes) && (tower->area))
        sfRenderWindow_drawCircleShape(window, tower->area, NULL);
}

void draw_grid(sfRenderWindow *window)
{
    sfRectangleShape *rect;

    for (int row = 0; row < GRID_ROWS; row++) {
        for (int col = 0; col < GRID_COLS; col++) {
            rect = sfRectangleShape_create();
            sfRectangleShape_setPosition(
                rect, (sfVector2f){col * SECTION_SIZE, row * SECTION_SIZE});
            sfRectangleShape_setSize(rect,
                (sfVector2f){SECTION_SIZE, SECTION_SIZE});
            sfRectangleShape_setFillColor(rect, sfTransparent);
            sfRectangleShape_setOutlineColor(rect, sfGreen);
            sfRectangleShape_setOutlineThickness(rect, 1);
            sfRenderWindow_drawRectangleShape(window, rect, NULL);
            sfRectangleShape_destroy(rect);
        }
    }
}

void format_time_string(char *time_str, int seconds)
{
    int i = 0;
    int j;
    char temp;

    if (seconds == 0) {
        time_str[i] = '0';
        i++;
    } else {
        while (seconds > 0) {
            time_str[i] = (seconds % 10) + '0';
            i++;
            seconds /= 10;
        }
        for (j = 0; j < i / 2; j++) {
            temp = time_str[j];
            time_str[j] = time_str[i - j - 1];
            time_str[i - j - 1] = temp;
        }
    }
    time_str[i] = '\0';
}

void draw_chronometer(sfRenderWindow *window, sfClock *clock,
    display_params_t *display)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    int seconds = elapsed_time.microseconds / 1000000;
    char time_str[10];
    sfFont *font = sfFont_createFromFile("assets/fast.ttf");
    sfText *text = sfText_create();

    if (!display->show_chronometer)
        return;
    format_time_string(time_str, seconds);
    sfText_setString(text, time_str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setPosition(text, (sfVector2f){1890, 10});
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}
