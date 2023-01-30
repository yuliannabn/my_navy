##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## makefile
##

NAME = navy

TARGET =	src/main.c						\
		src/messages/messages.c				\
		src/parsing/parsing.c				\
		src/parsing/init.c					\
		src/game/map_display.c				\
		src/game/val_tools.c				\
		src/game/navy.c						\
		src/players/receive_attack.c		\
		src/players/send_attack.c			\
		src/players/players.c				\
		src/connecting/send_pid.c			\
		src/connecting/get_pid.c			\

FLAGS = -W -Wall -Wpedantic -Wno-long-long -g -Werror

INCLUDE = -I include/

all = $(NAME)

$(NAME):
	cd lib; make
	gcc -o $(NAME) $(TARGET) $(INCLUDE) $(FLAGS) -L lib/ -lmy

clean:
	cd lib; make clean
	rm -f *#
	rm -f *~

fclean: clean
	cd lib; make fclean
	rm -f $(NAME)

re: fclean $(NAME)
