##
## EPITECH PROJECT, 2024
## B-SYN-200-LYN-2-1-projtester-marin.lagie
## File description:
## Makefile
##
SRC = ./src/main.c \
	./src/config/init.c \
	./src/file/scan.c \
	./src/file/my_getline.c \
	./src/file/getfile.c \
	./src/error/put_error.c \
	./src/mapper.c \
	./src/utils/array/arrays.c \
	./src/utils/array/free_strarray.c \
	./src/utils/array/my_strtok.c \
	./src/utils/array/my_str_to_word_array.c \
	./src/utils/array/add_ar_in_ar.c \
	./src/utils/count_char.c \
	./src/utils/string/my_isspace.c \
	./src/utils/string/my_memset.c \
	./src/utils/my_printf.c \
	./src/args.c \
	./src/execute.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -g3 -Wall -Wextra -Iinclude
NAME = projTester
all: $(NAME)

$(NAME): $(OBJ)
	gcc ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}
	rm -f vgcore.*
fclean: clean
	rm -f ${NAME}
re: fclean all
