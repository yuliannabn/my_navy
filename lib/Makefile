##
## EPITECH PROJECT, 2022
## MAKEFILE LIB
## File description:
## MAKEFILE
##

SRC =	standard/char.c				\
	standard/get_nbr.c				\
	standard/is_number.c			\
	standard/numbers.c				\
	standard/p_strlen.c				\
	standard/str_equal.c			\
	standard/str_to_word_array.c	\
	standard/string.c				\
	standard/free_array.c			\
	standard/array_length.c			\
	standard/nbr_string.c			\
	standard/strdup.c				\
	standard/str_cat.c				\
	reading/read_file.c				\
	reading/error_message.c			\

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#

fclean: clean
	rm -f $(NAME)

re: fclean all
