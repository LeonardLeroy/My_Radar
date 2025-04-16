##
## EPITECH PROJECT, 2024
## B-CPE-101-LYN-1-1-myprintf-leonard.leroy
## File description:
## Makefile
##

SRC = $(wildcard *.c)
OBJ	= $(SRC:.c=.o)
INCLUDE = -I./include
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../
	mkdir -p ../../include
	cp my.h ../../include

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

unit_tests: fclean all
	gcc -o ../unit_tests ../*.c ../../tests/*.c --coverage -lcriterion $(NAME)

tests_run: unit_tests
	../.././unit_tests
	rm -f ../../unit_tests*
	rm -f ../../*.gcno

re:	fclean all
