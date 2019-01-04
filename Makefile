##
## EPITECH PROJECT, 2019
## PSU_my_ls_2018
## File description:
## Makefile
##

SRC	=	main.c	\
		my_ls.c \
		informations_display.c

FLAGS	=	-Iinclude -Wall -Werror -Wextra -g

NAME	=	my_ls

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
