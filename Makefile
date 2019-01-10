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
		my_strcpy.c	\
		retrieve_infos.c

FLAGS	=	-Iinclude -Wall -Wextra -Werror -g -lmy -L.

NAME	=	my_ls

all: $(NAME)

$(NAME):
	make -C ./PSU_my_printf_2018/
	gcc -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./PSU_my_printf_2018/
	rm -f $(NAME)

re: fclean all
