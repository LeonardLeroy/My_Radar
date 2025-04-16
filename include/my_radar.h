/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** my_radar.h
*/

#include "math.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MY_RADAR_H
    #define MY_RADAR_H

    #define WIDTH 1950
    #define HEIGHT 1080

    #define POSITION_TOLERANCE 2.0
    #define COLLISION_TOLERANCE 1.0
    #define SPEED_TOLERANCE 0

    #define SECTION_SIZE 50
    #define GRID_ROWS (HEIGHT / SECTION_SIZE)
    #define GRID_COLS (WIDTH / SECTION_SIZE)

    #define NO_ERROR 0
    #define ERROR_BAD_ARGUMENT -1
    #define ERROR_TEXTURE -2
    #define ERROR_WINDOW -3
    #define ERROR_BACKGROUND -4
    #define ERROR_AIRCRAFT -5
    #define ERROR_TOWER -6
    #define ERROR_FILE -7
    #define ERROR_SECTION -8

    #define MYTRUE 1
    #define MYFALSE 0

typedef struct aircraft {
    sfRectangleShape *shape;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f departure;
    sfVector2f arrival;
    float speed;
    float delay;
    sfVector2f vector;
    sfClock *clock;
    sfTime start_time;
    float angle;
    int crashed;
} aircraft_t;

typedef struct control_tower {
    sfCircleShape *area;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    float radius;
} control_tower_t;

typedef struct {
    FILE *file;
    char **line;
    size_t *len;
} file_context_t;

typedef struct {
    aircraft_t *aircrafts;
    int num_aircrafts;
    control_tower_t *towers;
    int num_towers;
} entities_params_t;

typedef struct aircraft_node {
    aircraft_t *aircraft;
    struct aircraft_node *next;
} aircraft_node_t;

typedef struct section {
    sfIntRect bounds;
    aircraft_node_t *aircrafts;
    int num_aircrafts;
} section_t;

typedef struct {
    section_t **sections;
    control_tower_t *towers;
    int num_towers;
} collision_params_t;

typedef struct {
    sfVector2f pos;
    aircraft_t *aircraft;
} aircraft_params_t;

typedef struct {
    int show_grid;
    int show_hitboxes;
    int show_sprites;
    int show_chronometer;
} display_params_t;

typedef struct texture_manager {
    sfTexture **textures;
    int num_textures;
} texture_manager_t;

//aicraft_collision.c
int is_intersecting_aircrafts(aircraft_t *a1, aircraft_t *a2);
void check_and_handle_collision(aircraft_t *aircraft1, aircraft_t *aircraft2,
    control_tower_t *towers, int num_towers);
int is_in_control_area(aircraft_t *aircraft, control_tower_t *tower);
void handle_aircraft_visibility(aircraft_t *aircraft, sfColor color);

//check_colision.c
int check_in_control_area(aircraft_t *aircraft1, aircraft_t *aircraft2,
    collision_params_t *params);
void check_collision(aircraft_node_t *aircraft1, aircraft_node_t *aircraft2,
    control_tower_t *towers, int num_towers);
void process_section_collisions(collision_params_t *params, int row, int col);
void handle_aircraft_collisions(collision_params_t *params);
void process_collisions(section_t **sections, control_tower_t *towers,
    int num_towers);

//control_tower.c
control_tower_t *create_control_tower(sfVector2f position, float radius,
    texture_manager_t *texture_manager);
int set_tower_texture(control_tower_t *tower, sfTexture *texture);
control_tower_t *init_tower(sfVector2f position, float radius);
int init_tower_area(control_tower_t *tower);
int load_tower_texture(control_tower_t *tower);

//destroy_ressources.c
void destroy_resources(sfRenderWindow *window, entities_params_t *params,
    texture_manager_t *manager);
void destroy_resources_window(sfRenderWindow *window);
void destroy_resources_params_aircrafts(entities_params_t *params);
void destroy_resources_params_towers(entities_params_t *params);
void destroy_resources_params(entities_params_t *params);

//draw_functions.c
void draw_aircraft(sfRenderWindow *window, aircraft_t *aircraft,
    int show_hitboxes, int show_sprites);
void draw_control_tower(sfRenderWindow *window, control_tower_t *tower,
    int show_hitboxes, int show_sprites);
void draw_grid(sfRenderWindow *window);
void format_time_string(char *time_str, int seconds);
void draw_chronometer(sfRenderWindow *window, sfClock *clock,
    display_params_t *display);

//error_gestion.c
int write_error(int error_code);
int write_error_2(int error_code);
int write_error_3(int error_code);

//game_loop.c
int game_loop(sfRenderWindow *window, entities_params_t *params,
    sfSprite *background_sprite);
void handle_events_wrapper(sfRenderWindow *window, display_params_t *display);
int update_positions_wrapper(entities_params_t *params);
int are_aircrafts_in_motion(entities_params_t *params);
void draw_elements(sfRenderWindow *window, entities_params_t *params,
    display_params_t *display);

//handle_event.c
void handle_window_close(sfRenderWindow *window, sfEvent event);
void handle_events(sfRenderWindow *window, display_params_t *display);
void handle_key_press(sfEvent event, display_params_t *display);

//initialize_sections.c
void init_section(section_t *section, int j, int i);
section_t **initialize_sections(int rows, int cols);
void free_aircrafts_in_section(aircraft_node_t *aircrafts);
void free_sections(section_t **sections);

//load_entities_from_file.c
int load_entities_from_script(const char *filepath, entities_params_t *params,
    texture_manager_t *texture_manager);

//main.c
int main(int argc, char **argv);
int main_init_texture(texture_manager_t *texture_manager,
    entities_params_t *params, char *sfile);

//main2.c
void print_usage(void);
void bad_argument(char argc);
int handle_arguments(int argc, char **argv);
void print_simulation_results(int total_aircrafts, int survived_aircrafts,
    int crashed_aircrafts);
void display_simulation_results(entities_params_t *params);

//parse_functions.c
void parse_aircraft_line(char *line, aircraft_t *aircraft,
    texture_manager_t *texture_manager);
void parse_tower_line(char *line, control_tower_t *tower,
    texture_manager_t *texture_manager);
float my_atof_combined(const char *str);

//plane.c
aircraft_t *create_aircraft(sfVector2f departure, sfVector2f arrival,
    float speeddelay[2], texture_manager_t *texture_manager);
int set_aircraft_texture(aircraft_t *aircraft, sfTexture *texture);
aircraft_t *init_aircraft(sfVector2f departure, sfVector2f arrival,
    float speed, float delay);
int init_aircraft_shape(aircraft_t *aircraft);
int load_aircraft_texture(aircraft_t *aircraft);

//read_aircraft.c
int read_aircrafts(file_context_t *context, entities_params_t *params,
    texture_manager_t *texture_manager);

//read_tower.c
int read_towers(file_context_t *context, entities_params_t *params,
    texture_manager_t *texture_manager);

//script_loader.c
void increment_entity_count(char type, int *count_aircraft, int *count_towers);
int count_entities(const char *filepath, entities_params_t *params);
int initialize_entities(const char *filepath, entities_params_t *params,
    texture_manager_t *texture_manager);

//set_properties.c
void set_aircraft_properties(aircraft_t *aircraft, sfVector2f departure);
void set_tower_properties(control_tower_t *tower, sfVector2f position,
    float radius);

//texture_manager.c
texture_manager_t *init_texture_manager(int num_textures);
int load_all_textures(texture_manager_t *manager, const char **file_paths);
void destroy_texture_manager(texture_manager_t *manager);
sfTexture *load_texture(const char *file_path);
void free_texture_manager(texture_manager_t *manager);

//update_aicraft_positions.c
int check_and_add_aircraft(section_t **sections, aircraft_params_t *params);
void handle_collisions_and_cleanup(section_t **sections,
    control_tower_t *towers, int num_towers);
int update_aircraft_positions(entities_params_t *params);

//update.c
void update_aircraft_position_else(sfVector2f *position, sfVector2f direction,
    float speed, sfVector2f arrival);
void update_sprite_position(aircraft_t *aircraft, sfVector2f position);
void update_aircraft_position(aircraft_t *aircraft);

//window.c
sfRenderWindow *create_window(unsigned int width, unsigned int height,
    const char *title);
sfSprite *create_background_sprite(const char *file_path);

#endif /* MY_RADAR_H */
