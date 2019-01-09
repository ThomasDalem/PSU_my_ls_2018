##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## Makefile
##

SRC	=	main.c	\
		my_ls.c \
		informations_display.c \
		my_put_nbr.c \
		my_putchar.c \
		get_rights.c \
		retrieve_infos.c

FLAGS	=	-Iinclude -Wall -Wextra -Werror -g

NAME	=	my_ls

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
