##
## EPITECH PROJECT, 2024
## B-MUL-100-LYN-1-1-myradar-leonard.leroy
## File description:
## Makefile
##

NAME = my_radar

CC = gcc
GCCFLAGS = -L $(LIB_DIR) -I $(INCLUDE)
CFLAGS = $(GCCFLAGS) -Wall -Wextra -Werror

TEST = unit_tests

INCLUDE = ./include

LIB_DIR = ./lib/my

CRITERIONFLAGS = -lcriterion --coverage
CSFML_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm
TEST_FLAGS = $(CSFML_FLAGS) $(CRITERIONFLAGS)

SRCS =	src/error_gestion.c \
		src/main2.c \
		src/texture_manager.c \
		src/set_properties.c \
		src/window.c \
		src/handle_event.c \
		src/check_colision.c \
		src/load_entities_from_file.c \
		src/read_tower.c \
		src/read_aircraft.c \
		src/plane.c \
		src/control_tower.c \
		src/draw_functions.c \
		src/script_loader.c \
		src/parse_functions.c \
		src/update.c \
		src/update_aicraft_positions.c \
		src/game_loop.c \
		src/destroy_ressources.c \
		src/aicraft_collision.c \
		src/initialize_section.c \
		lib/my/my_putstr.c \
		lib/my/my_putchar.c \
		lib/my/my_getnbr.c \
		lib/my/my_str_to_word_array.c \
		lib/my/my_strncpy.c \
		lib/my/my_strlen.c \
		lib/my/count_nbr_words.c \
		lib/my/count_nbr_alphanum_per_word.c \
		lib/my/my_isalnum.c \
		lib/my/my_put_nbr.c \
		lib/my/my_strcmp.c

OBJS = $(SRCS:.c=.o)

MAIN_SRC = src/main.c

MAIN_OBJ = $(MAIN_SRC:.c=.o)

TEST_SRCS = tests/tests_my_radar.c

TEST_OBJS = $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MAIN_OBJ) $(CSFML_FLAGS)

unit_tests: CFLAGS += --coverage
unit_tests: fclean $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(OBJS) $(TEST_OBJS) $(TEST_FLAGS)

tests_run: unit_tests
	./$(TEST)
	gcovr --exclude tests/

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)
	rm -f src/*.gcno
	rm -f src/*.gcda
	rm -f tests/*.gcno
	rm -f tests/*.gcda
	rm -f lib/my/*.gcno
	rm -f lib/my/*.gcda
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
