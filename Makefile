##
## EPITECH PROJECT, 2022
## minilibc
## File description:
## Makefile
##

SRC = src/strlen.asm \
		src/strchr.asm \
		src/memcpy.asm \
		src/memset.asm \
		src/strcmp.asm \
		src/strstr.asm \
		src/strpbrk.asm \
		src/memmove.asm \
		src/strncmp.asm \
		src/strrchr.asm \
		src/strcspn.asm \
		src/strcasecmp.asm \

SRC-TEST = tests/test_my_strlen.c \
			tests/test_my_strchr.c \
			tests/test_my_memcpy.c \
			tests/test_my_memset.c \
			tests/test_my_strcmp.c \
			tests/test_my_strstr.c \
			tests/test_my_strpbrk.c \
			tests/test_my_memmove.c \
			tests/test_my_strncmp.c \
			tests/test_my_strrchr.c \
			tests/test_my_strcspn.c \
			tests/test_my_strcasecmp.c \

NAME = libasm.so

OBJ = $(SRC:.asm=.o)

OBJ-TEST = $(SRC-TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ld -shared -o $(NAME) $(OBJ)

tests_run:	re $(OBJ-TEST)
	gcc -o unit_tests -W -Wall -Wextra -fPIC $(OBJ-TEST) --coverage -lcriterion -ldl
	./unit_tests
	gcovr -r . --html-details --html -o tests.html

clean:
	rm -f src/*.o
	rm -f tests/*.o
	rm -f *.html
	rm -f *.css

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

re:	fclean all

%.o:	%.asm
	nasm -f elf64 -o $@ $<

.PHONY: all clean fclean re
