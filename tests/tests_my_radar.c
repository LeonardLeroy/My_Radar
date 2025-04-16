/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-leonard.leroy
** File description:
** tests_my_radar.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_radar.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(write_error, no_error)
{
    int result = write_error(NO_ERROR);
    cr_assert_eq(result, 0);
}

Test(write_error, error_texture, .init = redirect_all_std)
{
    int result = write_error(ERROR_TEXTURE);
    cr_assert_eq(result, 84);
    cr_assert_stderr_eq_str("Error texture\n");
}

Test(write_error, unknown_error)
{
    int result = write_error(999);
    cr_assert_eq(result, 84);
}

Test(write_error_2, error_background, .init = redirect_all_std)
{
    int result = write_error_2(ERROR_BACKGROUND);
    cr_assert_eq(result, 84);
    cr_assert_stderr_eq_str("Error background\n");
}

Test(write_error_2, unknown_error)
{
    int result = write_error_2(999);
    cr_assert_eq(result, 84);
}

Test(write_error_3, error_file, .init = redirect_all_std)
{
    int result = write_error_3(ERROR_FILE);
    cr_assert_eq(result, 84);
    cr_assert_stderr_eq_str("Error file\n");
}

Test(write_error_3, unknown_error, .init = redirect_all_std)
{
    int result = write_error_3(999);
    cr_assert_eq(result, 84);
    cr_assert_stderr_eq_str("Unknown error\n");
}

Test(print_usage, check_output, .init = redirect_all_std)
{
    print_usage();
    cr_assert_stdout_eq_str("Air traffic simulation panel\nUSAGE\n\n\t./my_radar [OPTIONS] path_to_script\n\tpath_to_script    The path to the script file.\nOPTIONS\n\n\t-h  print the usage and quit.\nUSER INTERACTIONS\n\n\t`L' key enable/disable hitboxes and areas.\n\t`S' key enable/disable sprites.\n\t`G' key enable/disable grid sections.\n\t`C' key enable/disable chronometer.\n");
}

Test(bad_argument, check_output, .init = redirect_all_std)
{
    bad_argument(3);
    cr_assert_stdout_eq_str("./my_radar: bad arguments: 2 given but 84 is required\nretry with -h\n");
}

Test(handle_arguments, no_arguments)
{
    char *argv[] = {"./my_radar"};
    int result = handle_arguments(1, argv);
    cr_assert_eq(result, ERROR_BAD_ARGUMENT);
}

Test(handle_arguments, help_argument, .init = redirect_all_std)
{
    char *argv[] = {"./my_radar", "-h"};
    int result = handle_arguments(2, argv);
    cr_assert_eq(result, 1);
    cr_assert_stdout_eq_str("Air traffic simulation panel\nUSAGE\n\n\t./my_radar [OPTIONS] path_to_script\n\tpath_to_script    The path to the script file.\nOPTIONS\n\n\t-h  print the usage and quit.\nUSER INTERACTIONS\n\n\t`L' key enable/disable hitboxes and areas.\n\t`S' key enable/disable sprites.\n\t`G' key enable/disable grid sections.\n\t`C' key enable/disable chronometer.\n");
}

Test(handle_arguments, valid_argument)
{
    char *argv[] = {"./my_radar", "script.txt"};
    int result = handle_arguments(2, argv);
    cr_assert_eq(result, NO_ERROR);
}

Test(init_texture_manager, valid_allocation)
{
    texture_manager_t *manager = init_texture_manager(5);
    cr_assert_not_null(manager);
    cr_assert_not_null(manager->textures);
    cr_assert_eq(manager->num_textures, 5);
    destroy_texture_manager(manager);
}

Test(init_texture_manager, memory_allocation_failure, .init = redirect_all_std)
{
    texture_manager_t *manager = init_texture_manager(0);
    cr_assert_null(manager);
    cr_assert_stderr_eq_str("Failed to allocate memory for texture manager.\n");
}

Test(load_all_textures, load_success)
{
    texture_manager_t *manager = init_texture_manager(2);
    const char* file_paths[] = {"assets/aircraft.png", "assets/tower.png"};
    int result = load_all_textures(manager, file_paths);
    cr_assert_eq(result, NO_ERROR);
    destroy_texture_manager(manager);
}

Test(load_all_textures, load_failure, .init = redirect_all_std)
{
    texture_manager_t *manager = init_texture_manager(1);
    const char* file_paths[] = {"invalid_path.png"};
    int result = load_all_textures(manager, file_paths);
    cr_assert_eq(result, ERROR_TEXTURE);
    cr_assert_stderr_eq_str("Failed to load texture\n");
    destroy_texture_manager(manager);
}

Test(destroy_texture_manager, valid_destruction)
{
    texture_manager_t *manager = init_texture_manager(2);
    destroy_texture_manager(manager);
    cr_assert_null(manager);
}

Test(load_texture, valid_texture)
{
    sfTexture *texture = load_texture("assets/aircraft.png");
    cr_assert_not_null(texture);
    sfTexture_destroy(texture);
}

Test(load_texture, invalid_texture, .init = redirect_all_std)
{
    sfTexture *texture = load_texture("invalid_path.png");
    cr_assert_null(texture);
    cr_assert_stderr_eq_str("Erreur: Impossible de charger la texture\n");
}

Test(free_texture_manager, valid_free)
{
    texture_manager_t *manager = init_texture_manager(2);
    free_texture_manager(manager);
    cr_assert_null(manager);
}

Test(free_texture_manager, null_manager, .init = redirect_all_std)
{
    free_texture_manager(NULL);
    cr_assert_stderr_eq_str("Texture manager is already NULL.\n");
}

Test(set_aircraft_properties, valid_properties)
{
    aircraft_t aircraft;
    sfVector2f departure = {100, 100};
    aircraft.shape = sfRectangleShape_create();
    aircraft.sprite = sfSprite_create();
    aircraft.texture = sfTexture_createFromFile("assets/aircraft.png", NULL);

    set_aircraft_properties(&aircraft, departure);
    sfVector2f shape_pos = sfRectangleShape_getPosition(aircraft.shape);
    cr_assert_float_eq(shape_pos.x, departure.x, 0.01);
    cr_assert_float_eq(shape_pos.y, departure.y, 0.01);

    sfRectangleShape_destroy(aircraft.shape);
    sfSprite_destroy(aircraft.sprite);
    sfTexture_destroy(aircraft.texture);
}

Test(set_tower_properties, valid_properties)
{
    control_tower_t tower;
    sfVector2f position = {200, 200};
    float radius = 50.0;
    tower.area = sfCircleShape_create();
    tower.sprite = sfSprite_create();

    set_tower_properties(&tower, position, radius);
    sfVector2f area_pos = sfCircleShape_getPosition(tower.area);
    cr_assert_float_eq(area_pos.x, position.x, 0.01);
    cr_assert_float_eq(area_pos.y, position.y, 0.01);

    sfCircleShape_destroy(tower.area);
    sfSprite_destroy(tower.sprite);
}

Test(game_loop, valid_execution)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "Test Window", sfResize | sfClose, NULL);
    sfSprite *background_sprite = sfSprite_create();
    entities_params_t params = {NULL, 0, NULL, 0};

    int result = game_loop(window, &params, background_sprite);

    cr_assert_eq(result, NO_ERROR);

    sfRenderWindow_destroy(window);
    sfSprite_destroy(background_sprite);
}

Test(handle_events_wrapper, valid_call)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "Test Window", sfResize | sfClose, NULL);
    display_params_t display = {0, 0, 1, 0};

    handle_events_wrapper(window, &display);

    cr_assert(true);

    sfRenderWindow_destroy(window);
}

Test(update_positions_wrapper, valid_update)
{
    entities_params_t params = {NULL, 0, NULL, 0};
    int result = update_positions_wrapper(&params);
    cr_assert_eq(result, NO_ERROR);
}

Test(are_aircrafts_in_motion, no_aircrafts)
{
    entities_params_t params = {NULL, 0, NULL, 0};
    int result = are_aircrafts_in_motion(&params);
    cr_assert_eq(result, MYFALSE);
}

Test(draw_elements, valid_draw)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "Test Window", sfResize | sfClose, NULL);
    entities_params_t params = {NULL, 0, NULL, 0};
    display_params_t display = {0, 0, 1, 0};

    draw_elements(window, &params, &display);

    cr_assert(true);

    sfRenderWindow_destroy(window);
}

Test(create_control_tower, valid_creation)
{
    texture_manager_t *texture_manager = init_texture_manager(2);
    texture_manager->textures[1] = sfTexture_createFromFile("assets/tower.png", NULL);
    control_tower_t *tower = create_control_tower((sfVector2f){100, 100}, 50, texture_manager);

    cr_assert_not_null(tower);
    cr_assert_not_null(tower->area);
    cr_assert_not_null(tower->sprite);
    cr_assert_not_null(tower->texture);

    sfCircleShape_destroy(tower->area);
    sfSprite_destroy(tower->sprite);
    free(tower);
    destroy_texture_manager(texture_manager);
}

Test(set_tower_texture, valid_texture)
{
    control_tower_t tower;
    sfTexture *texture = sfTexture_createFromFile("assets/tower.png", NULL);
    int result = set_tower_texture(&tower, texture);

    cr_assert_eq(result, 1);
    cr_assert_not_null(tower.sprite);
    cr_assert_not_null(tower.texture);
    sfSprite_destroy(tower.sprite);
    sfTexture_destroy(texture);
}

Test(init_tower, valid_initialization)
{
    control_tower_t *tower = init_tower((sfVector2f){100, 100}, 50);
    cr_assert_not_null(tower);
    cr_assert_float_eq(tower->position.x, 100, 0.01);
    cr_assert_float_eq(tower->position.y, 100, 0.01);
    cr_assert_float_eq(tower->radius, 50, 0.01);
    free(tower);
}

Test(create_aircraft, valid_creation)
{
    texture_manager_t *texture_manager = init_texture_manager(2);
    texture_manager->textures[0] = sfTexture_createFromFile("assets/aircraft.png", NULL);
    aircraft_t *aircraft = create_aircraft((sfVector2f){100, 100}, (sfVector2f){200, 200}, (float[]){1, 0}, texture_manager);

    cr_assert_not_null(aircraft);
    cr_assert_not_null(aircraft->shape);
    cr_assert_not_null(aircraft->sprite);
    cr_assert_not_null(aircraft->texture);
    sfRectangleShape_destroy(aircraft->shape);
    sfSprite_destroy(aircraft->sprite);
    free(aircraft);
    destroy_texture_manager(texture_manager);
}

Test(set_aircraft_texture, valid_texture)
{
    aircraft_t aircraft;
    sfTexture *texture = sfTexture_createFromFile("assets/aircraft.png", NULL);
    int result = set_aircraft_texture(&aircraft, texture);
    
    cr_assert_eq(result, 1);
    cr_assert_not_null(aircraft.sprite);
    cr_assert_not_null(aircraft.texture);
    sfSprite_destroy(aircraft.sprite);
    sfTexture_destroy(texture);
}

Test(init_aircraft, valid_initialization)
{
    aircraft_t *aircraft = init_aircraft((sfVector2f){100, 100}, (sfVector2f){200, 200}, 1, 0);
    cr_assert_not_null(aircraft);
    cr_assert_float_eq(aircraft->departure.x, 100, 0.01);
    cr_assert_float_eq(aircraft->departure.y, 100, 0.01);
    cr_assert_float_eq(aircraft->arrival.x, 200, 0.01);
    cr_assert_float_eq(aircraft->arrival.y, 200, 0.01);
    cr_assert_float_eq(aircraft->speed, 1, 0.01);
    cr_assert_float_eq(aircraft->delay, 0, 0.01);
    free(aircraft);
}

Test(draw_aircraft, draw_sprite)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "Test Window", sfResize | sfClose, NULL);
    aircraft_t aircraft;
    aircraft.sprite = sfSprite_create();
    aircraft.shape = sfRectangleShape_create();
    
    cr_redirect_stdout();
    draw_aircraft(window, &aircraft, 0, 1);
    cr_assert_stdout_eq_str("");
    sfSprite_destroy(aircraft.sprite);
    sfRectangleShape_destroy(aircraft.shape);
    sfRenderWindow_destroy(window);
}

Test(draw_control_tower, draw_sprite)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){800, 600, 32}, "Test Window", sfResize | sfClose, NULL);
    control_tower_t tower;
    tower.sprite = sfSprite_create();
    tower.area = sfCircleShape_create();
    
    cr_redirect_stdout();
    draw_control_tower(window, &tower, 0, 1);
    cr_assert_stdout_eq_str("");
    sfSprite_destroy(tower.sprite);
    sfCircleShape_destroy(tower.area);
    sfRenderWindow_destroy(window);
}

Test(count_nbr_alphanum_per_word, basic_test)
{
    int result = count_nbr_alphanum_per_word("Hello world", 0);
    cr_assert_eq(result, 5);
}

Test(count_nbr_alphanum_per_word, multiple_words)
{
    int result = count_nbr_alphanum_per_word("Hello world", 6);
    cr_assert_eq(result, 5);
}

Test(count_nbr_words, basic_test)
{
    int result = count_nbr_words("Hello world");
    cr_assert_eq(result, 2);
}

Test(count_nbr_words, single_word)
{
    int result = count_nbr_words("Hello");
    cr_assert_eq(result, 1);
}

Test(my_getnbr, positive_number)
{
    int result = my_getnbr("123");
    cr_assert_eq(result, 123);
}

Test(my_getnbr, negative_number)
{
    int result = my_getnbr("-123");
    cr_assert_eq(result, -123);
}

Test(my_getnbr, invalid_number)
{
    int result = my_getnbr("abc");
    cr_assert_eq(result, 0);
}

Test(my_isalnum, alphanumeric)
{
    int result = my_isalnum('a');
    cr_assert_eq(result, 1);
}

Test(my_isalnum, non_alphanumeric)
{
    int result = my_isalnum('!');
    cr_assert_eq(result, 0);
}

Test(my_str_to_word_array, basic_test)
{
    char **result = my_str_to_word_array("Hello world");
    cr_assert_str_eq(result[0], "Hello");
    cr_assert_str_eq(result[1], "world");
}

Test(my_str_to_word_array, single_word)
{
    char **result = my_str_to_word_array("Hello");
    cr_assert_str_eq(result[0], "Hello");
}

Test(init_texture_manager, zero_textures)
{
    texture_manager_t *manager = init_texture_manager(0);
    cr_assert_not_null(manager);
    cr_assert_eq(manager->num_textures, 0);
    destroy_texture_manager(manager);
}
